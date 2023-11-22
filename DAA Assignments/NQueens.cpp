#include <iostream>
#include <cmath>
using namespace std;

// Function to print the current configuration of the chessboard.
// It takes the size n and an array col that represents the column positions of queens.
void print(int n, int col[])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // If there's a queen in this cell, print its position (1-based)
            if (col[i] == j) // col[i] the column position of the queen in row i with the current column j. If they match, it prints the position of the queen.
                cout << i + 1 << " ";
            else
                cout << "0 ";
        }
        cout << "\n"; // Newline character for the next row.
    }
    cout << "\n";
}

// Function to check if it's possible to place a queen in a particular row and column
bool place(int queen, int c, int col[]) // c is the column position of the queen to be placed in the current row (queen)
{
    int j = 0; // j iterates through prev placed queens.
    while (j < queen)
    {
        if (col[j] == c || abs(col[j] - c) == abs(j - queen)){
            return false;
        }
        j++;
    }
    return true;
}

// Recursive function to solve the N-Queens problem
bool nqueen(int queen, int n, int col[])
{
    int fl = 0; // Initializes a flag fl to 0, which will be used to keep track of whether a queen could be placed in the current row. If fl remains 0 after trying all columns in the current row, it means it couldn't find a valid position for the current queen.

    for (int i = 0; i < n; i++)
    {
        // inside the loop, it calls the place function to check if it's possible to place the queen in the current row (queen) and column (i) without conflicts with previously placed queens. If place returns true, it means a valid position is found.

        if (place(queen, i, col))
        {
            col[queen] = i; // If a valid position is found, it updates the col array by placing the queen in the current cell (col[queen] = i), where queen represents the row and i represents the column.
            cout << "Placing Queen " << queen + 1 << "\n";
            print(n, col);
            if (queen == n - 1)            // It checks if the current queen is the last queen to be placed (queen == n - 1). If so, it means all queens are successfully placed without conflicts
                return true;               // All queens are placed, solution found
            if (nqueen(queen + 1, n, col)) // If the current queen is not the last one to be placed, it recursively calls nqueen for the next queen (queen + 1). This recursive call attempts to place the next queen, continuing the search for a solution.
                return true;
            col[queen] = -1; // Backtrack: Reset the position of the current queen. If the recursive calls to nqueen do not result in a solution, the program backtracks by resetting the position of the current queen (col[queen] = -1), indicating that the current position is invalid. It prints a message indicating the backtracking and calls the print function to show the chessboard configuration after backtracking.

            cout << "Backtracking Queen " << queen + 1 << "\n";
            print(n, col);
            fl = 1;
        }
    }
    if (!fl)
        cout << "Unable to place Queen " << queen + 1 << "\n\n";
    return false;
}

int main()
{
    int n;
    cout << "Enter Size of chessboard : ";
    cin >> n;
    // Check if the chessboard size is less than or equal to 3, and if so, exit
    if (n <= 3)
    {
        cout << "\nSize should be more than 3\n";
        return 0;
    }
    int col[n];
    for (int i = 0; i < n; i++){
        col[i] = -1;   // Initialize column positions of queens
    }
    
    nqueen(0, n, col); // Start solving the N-Queens problem
    return 0;
}

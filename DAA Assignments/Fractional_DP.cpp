#include <iostream>
using namespace std;

// Function to solve the 0/1 Knapsack problem using dynamic programming
int knapsackSolver(int weight[], int profit[], int n, int maxWeight) {
    // DP array to store the maximum profit for different items and capacities
    int dp[n + 1][maxWeight + 2];//initializes 2D dp array

    // Initializing the DP array with zeros
    for (int i = 0; i <= n; i++) {//iterates through items
        for (int j = 0; j <= maxWeight; j++) {//through capacity
            if (i == 0 || j == 0) { //first row and col items are set to 0
                dp[i][j] = 0; //sets all array values to 0
            } else {
                dp[i][j] = 0;
            }
        }
    }

    // Filling the DP array using a bottom-up approach
    for (int i = 1; i <= n; i++) {  //iterates through items
        for (int j = i; j <= maxWeight; j++) {//iterates through capacities
            if (weight[i - 1] <= j) {//checks if cur itm wt fits in cur cap
                dp[i][j] = max(profit[i - 1] + dp[i - 1][j - weight[i - 1]], dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // Displaying the tabulation of the items (DP array)
    cout << "\nTabulation of the items:\n\n";
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= maxWeight; j++) {
            cout.width(5);
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    // Returning the maximum profit that can be obtained
    return dp[n][maxWeight];
}

int main() {
    int n, capacity;
    cout << "Enter the number of elements: ";
    cin >> n;
    int weight[n], profit[n];
    cout << "Enter the weight of the bag: ";
    cin >> capacity;

    // Taking input for weights of the items
    cout << "Enter the weights of the " << n << " items:\n";
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }

    // Taking input for profits of the items
    cout << "Enter the profits of the " << n << " items:\n";
    for (int i = 0; i < n; i++) {
        cin >> profit[i];
    }

    // Calculating and displaying the maximum profit that can be obtained
    int maxProfit = knapsackSolver(weight, profit, n, capacity);
    cout << "\nThe maximum profit that can be obtained is: " << maxProfit << endl;
    return 0;
}
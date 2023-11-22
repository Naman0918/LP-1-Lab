#include <iostream>
#include <algorithm>

using namespace std;

void display(int subset[], int subsetsize)
{
    for (int i = 0; i < subsetsize; i++)
    {
        cout << subset[i] << " ";
    }
    cout << endl;
}

void subsetsum(int arr[], int n, int index, int sum, int currsum, int subset[], int subsetsize)
{
    if (currsum == sum)
    {
        display(subset, subsetsize);
        return;
    }

    for (int i = index; i < n; i++)
    {
        if (currsum + arr[i] <= sum)
        {
            currsum += arr[i];
            subset[subsetsize] = arr[i];
            subsetsum(arr, n, i + 1, sum, currsum, subset, subsetsize + 1);
            currsum -= arr[i];
        }
    }
}

int main()
{
    int n;
    cout << "Enter number of elements in the set: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the set:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int targetSum;
    cout << "Enter the target sum: ";
    cin >> targetSum;

    int subset[n];
    int initial = 0;

    subsetsum(arr, n, 0, targetSum, initial, subset, 0);
    return 0;
}
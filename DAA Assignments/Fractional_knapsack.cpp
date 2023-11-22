#include <iostream>
#include <algorithm>

using namespace std;

// Struct to represent each item with its value, weight, and value-to-weight ratio
struct Item
{
    int value;
    int weight;
    double valuePerWeight;
};

// BubbleSort algorithm to sort items based on their value-to-weight ratio
void bubbleSort(Item arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (arr[j].valuePerWeight < arr[j + 1].valuePerWeight)
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Function to solve the fractional knapsack problem
double fractionalKnapsack(Item arr[], int numItems, int capacity)
{
    double maxValue = 0.0;

    // Sorting items based on their value-to-weight ratio using bubble sort
    bubbleSort(arr, numItems);

    // Filling the knapsack with items having the highest value-to-weight ratio
    for (int i = 0; i < numItems; i++)
    {
        if (capacity >= arr[i].weight)
        {
            maxValue += arr[i].value;
            capacity -= arr[i].weight;
        }
        else
        {
            // Taking a fraction of the item if the capacity is less than the item's weight
            double fraction = (double)capacity / (double)arr[i].weight;
            maxValue += fraction * arr[i].value;
            break;
        }
    }

    return maxValue;
}

int main()
{
    int numItems, capacity;
    cout << "Enter the number of items: ";
    cin >> numItems;

    // Array to store the items
    Item items[numItems];

    // Taking input for each item's value and weight
    cout << "Enter the value and weight of each item:\n";
    for (int i = 0; i < numItems; ++i)
    {
        int value, weight;
        cout << "Item " << i + 1 << " value: ";
        cin >> value;
        cout << "Item " << i + 1 << " weight: ";
        cin >> weight;
        items[i].value = value;
        items[i].weight = weight;
        items[i].valuePerWeight = (double)value / (double)weight;
    }

    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    // Finding the maximum value that can be obtained in the knapsack
    double maxTotalValue = fractionalKnapsack(items, numItems, capacity);
    cout << "Maximum value in knapsack = " << maxTotalValue << endl;

    return 0;
}

// Item 1 value: 60
// Item 1 weight: 10
// Item 2 value: 100
// Item 2 weight: 20
// Item 3 value: 120
// Item 3 weight: 30
// Enter the capacity of the knapsack: 50
// Maximum value in knapsack = 240
#include<iostream>
using namespace std;

// Function to perform Bubble Sort on an array
void bubbleSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - 1 - i; j++) 
        {
            if (arr[j] > arr[j + 1])  //greater than
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Function to print the elements of an array
void printArray(const int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    // Variable Declaration
    int n;
    cout << "Enter no of elements in array = ";
    cin >> n;

    // Dynamic Array Allocation
    int *arr = new int[n];

    // Array Input
    cout << "\nEnter elements in array = ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Bubble Sort
    bubbleSort(arr, n);

    // Sorted Array Output
    cout << "\nSorted array is ";
    printArray(arr, n);

    // Memory Deallocation
    delete[] arr;

    return 0;
}

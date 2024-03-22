#include <iostream>

using namespace std;

void printArray(int arr[], int start, int end);

int sortArray[7];

void merge(int arr[], int start, int mid, int end)
{
    int size1 = (mid - start) + 1;
    int size2 = end - start;

    int arr1[size1];
    int arr2[size2];

    for (int i = 0; i < size1; i++)
    {
        arr1[i] = arr[size1 + i];
    }

    for (int i = 0; i < size2; i++)
    {
        arr2[i] = arr[size2 + i];
    }

    printArray(arr1, start, end);
}

void mergeSort(int arr[], int start, int end)
{
    // printArray(arr, start, end);
    if (start >= end)
    {
        return;
    }

    int mid = (start + end) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

void printArray(int arr[], int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[7] = {9, 5, 3, 7, 6, 1, 2};
    mergeSort(arr, 0, 6);

    // printArray(sortArray, 0, 6);

    return 0;
}
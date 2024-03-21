#include <iostream>

using namespace std;

void printArray(int arr[], int start, int end);

int sortArray[7];

void merge(int arr[], int start, int mid, int end)
{
    // int arr1[mid + 1];
    // int arr2[(end - mid) + 1];
    int first = start, second = mid + 1;
    int k = start;

    while (first <= mid || second <= end)
    {
        if (arr[first] < arr[second])
        {
            sortArray[k] = arr[first];
            first++;
            k++;
        }
        else
        {
            sortArray[k] = arr[second];
            second++;
            k++;
        }
    }
    printArray(arr, start, end);
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

    printArray(sortArray, 0, 6);

    return 0;
}
#include <iostream>

using namespace std;

void printArray(int arr[], int start, int end);

void mergeSort(int arr[], int start, int end)
{
    if (start > end)
    {
        return;
    }
    printArray(arr, start, end);
    int mid = (start + end) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
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

    return 0;
}
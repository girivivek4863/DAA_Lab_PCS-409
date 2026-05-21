/*Merge Sort with Comparisons and Inversions
Statement: Given an unsorted array of integers, sort it using Merge Sort and count the number of
comparisons and inversions.
Approach
● Merge Sort: A divide-and-conquer algorithm that splits the array, sorts each half, and
merges them.
● Comparisons: Counted when merging two subarrays.
● Inversions: Counted when a larger element appears before a smaller one in sorting.
Time Complexity: O(n log n)*/

#include <iostream>
using namespace std;


int comparisons = 0, inversions = 0;
// Merge function to combine two sorted halves
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int leftArr[n1], rightArr[n2];
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        rightArr[i] = arr[mid + 1 + i];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        comparisons++;
        if (leftArr[i] <= rightArr[j])
        {
            arr[k++] = leftArr[i++];
        }
        else
        {
            arr[k++] = rightArr[j++];
            inversions += (n1 - i); // Count inversions
        }
    }
    while (i < n1)
        arr[k++] = leftArr[i++];
    while (j < n2)
        arr[k++] = rightArr[j++];
}
// Merge Sort function
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
int main()
{
    int T, n;
    cin >> T;
    while (T--)
    {
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        comparisons = inversions = 0;
        mergeSort(arr, 0, n - 1);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << "\nComparisons = " << comparisons << "\n";
        cout << "Inversions = " << inversions << "\n";
    }
    return 0;
}

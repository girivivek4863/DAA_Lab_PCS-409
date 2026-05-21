/*Find Key and Count Duplicates (Binary Search)
Time Complexity: O(logn)
Approach:
1. Since the array is sorted, use binary search to find the first occurrence of the key.
2. Use binary search to find the last occurrence.
3. The count of occurrences is last occurrence index - first occurrence index + 1.*/

#include <iostream>
using namespace std;
// Function to find the first occurrence of the key
int firstOccurrence(int arr[], int n, int key)
{
    int low = 0, high = n - 1, result = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
        {
            result = mid;
            high = mid - 1; 
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return result;
}

int lastOccurrence(int arr[], int n, int key)
{
    int low = 0, high = n - 1, result = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
        {
            result = mid;
            low = mid + 1; 
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return result;
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, key;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cin >> key;
        int first = firstOccurrence(arr, n, key);
        int last = lastOccurrence(arr, n, key);
        if (first == -1)
        {
            cout << "Key not present" << endl;
        }
        else
        {
            cout << key << " - " << (last - first + 1) << endl;
        }
    }
    return 0;
}

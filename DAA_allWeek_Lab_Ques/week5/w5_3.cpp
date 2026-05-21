/*Find Common Elements in Two Sorted Arrays
Algorithm (Time Complexity: O(m + n))
1. Use two pointers, one for each array.
2. If elements match, add them to the result.
3. If an element in the first array is smaller, move forward in the first array.
4. Otherwise, move forward in the second array.
*/

#include <iostream>
using namespace std;
void findCommonElements(int arr1[], int m, int arr2[], int n)
{
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (arr1[i] == arr2[j])
        {
            cout << arr1[i] << " ";
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j])
            i++;
        else
            j++;
    }
    cout << endl;
}
int main()
{
    int m, n;
    cin >> m;
    int arr1[m];
    for (int i = 0; i < m; i++)
        cin >> arr1[i];
    cin >> n;
    int arr2[n];
    for (int i = 0; i < n; i++)
        cin >> arr2[i];
    findCommonElements(arr1, m, arr2, n);
    return 0;
}
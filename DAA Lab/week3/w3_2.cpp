/*Selection Sort with Comparisons and Swaps
Time Complexity:
● Best, Worst, and Average Case: O(n^2)
Space Complexity: O(1) (In-place sorting)*/

#include <iostream>
using namespace std;
void selectionSort(int arr[], int n, int &comparisons, int &swaps) {
comparisons = 0;
swaps = 0;
for (int i = 0; i < n - 1; i++) {
int minIndex = i;
for (int j = i + 1; j < n; j++) {
comparisons++;
if (arr[j] < arr[minIndex])
minIndex = j;
}
if (minIndex != i) {
swap(arr[i], arr[minIndex]);
swaps++;
}
}
}
// Driver function
int main() {
int T, n;
cin >> T;
while (T--) {
cin >> n;
int arr[n];
for (int i = 0; i < n; i++) cin >> arr[i];
int comparisons = 0, swaps = 0;
selectionSort(arr, n, comparisons, swaps);
// Output sorted array
for (int i = 0; i < n; i++) cout << arr[i] << " ";
cout << "\ncomparisons = " << comparisons;
cout << "\nswaps = " << swaps << endl;
}
return 0;
}

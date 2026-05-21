/*Insertion Sort with Comparisons and Shifts
Time Complexity:
● Best Case (Already Sorted Array): O(n)
● Worst Case (Reversed Array): O(n^2)
● Average Case: O(n^2)
Space Complexity: O(1) (In-place sorting)*/

#include <iostream>
using namespace std;
void insertionSort(int arr[], int n, int &comparisons, int &shifts) {
comparisons = 0;
shifts = 0;
for (int i = 1; i < n; i++) {
int key = arr[i];
int j = i - 1;
// Compare and shift elements
while (j >= 0 && arr[j] > key) {
comparisons++;
arr[j + 1] = arr[j];
shifts++;
j--;
}
arr[j + 1] = key;
shifts++;
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
int comparisons = 0, shifts = 0;
insertionSort(arr, n, comparisons, shifts);
// Output sorted array
for (int i = 0; i < n; i++) cout << arr[i] << " ";
cout << "\ncomparisons = " << comparisons;
cout << "\nshifts = " << shifts << endl;
}
return 0;
}

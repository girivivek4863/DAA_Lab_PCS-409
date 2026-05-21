/*Find Two Elements with Given Sum
Algorithm (Time Complexity: O(n log n))
1. Sort the array (O(n log n)).
2. Use the two-pointer technique to check if any two elements sum to the given key.
3. If a pair is found, print it; otherwise, print "No Such Element Exist."*/

#include <iostream>
#include <algorithm>
using namespace std;
void findPairWithSum(int arr[], int n, int key) {
sort(arr, arr + n); // O(n log n)
int left = 0, right = n - 1;
while (left < right) {
int sum = arr[left] + arr[right];
if (sum == key) {
cout << arr[left] << " " << arr[right] << endl;
return;
}
else if (sum < key)
left++;
else
right--;
}
cout << "No Such Element Exist\n";
}
int main() {
int n, key;
cin >> n;
int arr[n];
for (int i = 0; i < n; i++)
cin >> arr[i];
cin >> key;
findPairWithSum(arr, n, key);
return 0;
}
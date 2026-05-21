/*Find Maximum Occurring Alphabet
Algorithm (Time Complexity: O(n))
1. Use an array of size 26 (since there are 26 alphabets) to store the frequency of each
character.
2. Iterate over the array and update the frequency count.
3. Find the character with the maximum frequency.
4. If no character has a frequency greater than 1, print "No Duplicates Present."
*/

#include <iostream>
#include <unordered_map>
using namespace std;
void findMaxOccurringAlphabet(int n, char arr[])
{
    unordered_map<char, int> freq;
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }
    char maxChar = '\0';
    int maxCount = 0;
    for (auto it : freq)
    {
        if (it.second > maxCount)
        {
            maxCount = it.second;
            maxChar = it.first;
        }
    }
    if (maxCount == 1)
        cout << "No Duplicates Present\n";
    else
        cout << maxChar << " - " << maxCount << endl;
}
int main()
{
    int n;
    cin >> n;
    char arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    findMaxOccurringAlphabet(n, arr);
    return 0;
}

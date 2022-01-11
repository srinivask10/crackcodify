/*
Lapindrome is defined as a string which when split in the middle, 
gives two halves having the same characters and same frequency of each character. 
If there are odd number of characters in the string, we ignore the middle character
 and check for lapindrome. For example gaga is a lapindrome, 
since the two halves ga and ga have the same characters with same frequency. 
Also, abccab, rotor and xyzxy are a few examples of lapindromes. 
Note that abbaab is NOT a lapindrome. 
The two halves contain the same characters but their frequencies do not match.
Your task is simple. Given a string, you need to tell if it is a lapindrome.

Input:
First line of input contains a single integer T, the number of test cases.
Each test is a single line containing a string S composed of only lowercase English alphabet.

Output:
For each test case, output on a separate line: "YES" if the string is a lapindrome and "NO" if it is not.

Constraints:
1 ≤ T ≤ 100
2 ≤ |S| ≤ 1000, where |S| denotes the length of S

Example:
Input:
6
gaga
abcde
rotor
xyzxy
abbaab
ababc


Output:
YES
NO
YES
YES
NO
NO

*/


#include <bits/stdc++.h>
using namespace std;

int main()
{
    unsigned long long int t;
    cin >> t;
    
    string str;
    int i;
    
    while (t--)
    {
        char first[26] = { 0 }, second[26] = { 0 };

        cin >> str;
        for (i = 0; i < str.length()/2; i++)
        {
            first[str[i]-'a']++;
        }
        for (i = (str.length()+1)/2; i < str.length(); i++)
        {
            second[str[i]-'a']++;
        }
        
        for (i = 0; i < 26; i++)
            if (first[i] != second[i])
                break;
                
        if (i == 26)
            cout << "YES\n";
        else
            cout << "NO\n";

    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}

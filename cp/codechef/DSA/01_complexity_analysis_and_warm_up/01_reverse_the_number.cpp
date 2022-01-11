/*
Given an Integer N, write a program to reverse it.

Input
The first line contains an integer T, total number of testcases. Then follow T lines, each line contains an integer N.

Output
For each test case, display the reverse of the given number N, in a new line.

Constraints
1 ≤ T ≤ 1000
1 ≤ N ≤ 1000000
Example
Input
4
12345
31203
2123
2300
Output
54321
30213
3212
32
*/


#include <bits/stdc++.h>
using namespace std;

unsigned long long int reverse(unsigned long long int num)
{
    unsigned long long int rev = 0;
    while (num != 0)
    {
        rev = (rev*10) + (num%10);
        num /= 10;
    }
    
    return rev;
}

int main()
{
    unsigned long long int t, num;
    cin >> t;
    while (t--)
    {
        cin >> num;
        cout << reverse(num) << "\n";
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}



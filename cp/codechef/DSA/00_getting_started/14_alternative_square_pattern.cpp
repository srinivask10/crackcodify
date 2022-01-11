/*
You're given a number N. Print the first N lines of the below-given pattern.

1 2 3 4 5
10 9 8 7 6
11 12 13 14 15
20 19 18 17 16
21 22 23 24 25
30 29 28 27 26

Input:
First-line will contain the number N.

Output:
Print the first N lines of the given pattern.


Constraints
1≤N≤200

Sample Input 1:
4
Sample Output 1:
1 2 3 4 5
10 9 8 7 6
11 12 13 14 15
20 19 18 17 16

Sample Input 2:
2
Sample Output 2:
1 2 3 4 5
10 9 8 7 6

EXPLANATION:
In the first example, we'll print the first 4 lines of the given pattern.
In the second example, we'll print the first 2 lines of the given pattern.
*/

#include <iostream>
using namespace std;

#define PER_LINE_NUMBERS 5

int main() {
	int n;
	cin >> n;
	
	int flip = 0;
	
	for (int i = 0; i < n; i++)
	{
	    for (int j = 0; j < PER_LINE_NUMBERS; j++)
	    {
	        if (!flip)
	            cout << (PER_LINE_NUMBERS*i)+j+1 << " ";
	        else
	            cout << (PER_LINE_NUMBERS*i)+(PER_LINE_NUMBERS-j) << " ";
	    }
	    cout << "\n";
	    flip = !flip;
	}
	
	return 0;
}

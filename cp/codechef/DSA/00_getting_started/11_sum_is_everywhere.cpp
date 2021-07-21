/*
You are given a number N and find the sum of the first N odd and even numbers in a line separated by space. 
All even and odd numbers should be greater than 0.

Input:
First-line will contain the number N.
Output:
Print the sum of the first N odd and even numbers in a line separated by space.

Constraints
1≤N≤10^6

Sample Input 1:
4
Sample Output 1:
16 20

Sample Input 2:
1
Sample Output 2:
1 2

EXPLANATION:
In the first example, (1 + 3 + 5 + 7) = 16 and (2 + 4 + 6 + 8) = 20.
In the second example, only one odd that is 1 and only one even that is 2.
*/



/* 
n*n
Sum of first two odd numbers = 1 + 3 = 4 (4 = 2 x 2). 
Sum of first three odd numbers = 1 + 3 + 5 = 9 (9 = 3 x 3). 
Sum of first four odd numbers = 1 + 3 + 5 + 7 = 16 (16 = 4 x 4).
*/

/*
n*(n+1)
nth term in the AP	Sum of Even Numbers Formula Sn = n(n+1)	Verification of the sum
1	1(1+1) =	1×2 = 2		2
2	2(2+1) = 	2×3 = 6		2+4 = 6
3	3(3+1) =	3×4 = 12	2+4+6 = 12
4	4(4+1) = 	4x5 = 20	2+4+6+8=20

*/

#include <iostream>
using namespace std;

int main() {
	unsigned long long int n;
	cin >> n;
	cout << (n*n) << " " << (n*(n+1)) << "\n";
	return 0;
}

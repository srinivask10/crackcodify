#include <iostream>

using namespace std;

/* 
    (n & n-1) has same bits as n except rightmost set bit.
    e.g., number 11 is 1011.
    (1011 & 1010) = (1010)
    (1010 & 1001) = (1000)
    (1000 & 0111) = (0000)
    So, above 3 operations for 3 bits.
 */

int count_ones_in_binrep_number(int n)
{

    int count = 0;

    while (n > 0)
    {
        count++;
        n = (n & (n-1));
    }

    return count;
}

int main()
{
    int n;
    cin >> n;

    cout << count_ones_in_binrep_number(n);
    
    return 0;
}
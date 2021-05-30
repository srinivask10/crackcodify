#include <iostream>
#include <vector>

using namespace std;

/* Find unique number in an array where all numbers except one appears twice.

Use XOR. If number appears twice, it cuts of itself.
Number XORed with itself gives 0.
So, do XOR if each number in array, you will reamin only with unique number 
since all other numbers are appearing twice and gets cancelled to 0 due to XORing.
*/

int unique(int a[], int n)
{
    int unique_num = 0;
    for (int i = 0; i < n; i++)
        unique_num = unique_num ^ a[i];

    return unique_num;
}

/* Find 2 unique numbers in an array where all numbers except 2 are present twice.

Use XOR. If number appears twice, it cuts of itself.
Number XORed with itself gives 0.

XOR all numbers in array. You will get XOR of 2 unique numbers say UNIQUE_XOR_2.
Find rightmost set bit position in UNIQUE_XOR_2.
Then XOR numbers in array with the earlier result UNIQUE_XOR_2 if number in array have its bit set at same position as rightmost set bit of UNIQUE_XOR_2.
You will get UNIQUE_1. which is first unique number.
XOR of UNIQUE_1 and UNIQUE_XOR_2 (xor of uniques) will give UNIQUE_2.
So, you got both numbers.
e.g., {2, 4, 6, 7, 4, 5, 6, 2}
 - Uniques are 7 & 5.
 - UNIQUE_XOR_2 will be 2 (XOR of 7 & 5).
 - XOR 2 with all numbers where 2nd bit is set (since 2nd bit in 2 is set).
 - This will give us 7 UNIQUE_1.
 - UNIQUE_2 = 7 XOR 2 = 5
*/

vector<int> two_unique_numbers(int a[], int n)
{
    int xor_of_two_uniques = 0, unique_2 = 0, unique_1 = 0;
    vector<int> uniques;

    // Gives XOR of both uniques.
    for (int i = 0; i < n; i++)
        xor_of_two_uniques = xor_of_two_uniques ^ a[i];

    //Find position of rightmost bit set (starting 0).
    int temp = xor_of_two_uniques;
    int position = 0;
    while (!(temp & 1))
    {
        position++;
        temp = temp >> 1;
    }

    unique_1 = xor_of_two_uniques;
    //XOR with numbers whose position th bit is set.
    for (int i = 0; i < n; i++)
        if (a[i] & (1 << position))
            unique_1 = unique_1 ^ a[i];

    /*
    for (int i = 0; i < n; i++)
        if ((xor_of_two_uniques & a[i]) == xor_of_two_uniques)
            unique_1 = unique_1 ^ a[i];
    */

    unique_2 = unique_1 ^ xor_of_two_uniques;

    cout << unique_1 << " " << unique_2 << endl;

    uniques.push_back(unique_1);
    uniques.push_back(unique_2);

    return uniques;
}

/* Find unique number in an array where all numbers except one appear N times.
    Count how many numbers have each bit set 
    (assume number if of 64 bit, take array of 64 and count how many numbers have appropriate bit set). 
*/
int unique_in_all_appearing_x_times(int a[], int n, int xtimes)
{
    int unique = 0;
    int count;

    for (int i = 0; i < 64; i++)
    {
        count = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[j] & (1 << i))
            {
                count++;
            }
        }

        if ((count % xtimes) != 0)
            unique = (unique | (1 << i));
    }


    return unique;
}


int main()
{

    int a[] = {2, 2, 3 , 5, 3, 7, 7};
    int size = sizeof(a)/sizeof(a[0]);
    cout << unique(a, size) << endl;

    int a1[] = {2, 4, 6, 7, 4, 5, 6, 2};
    int size1 = sizeof(a1)/sizeof(a1[0]);
    two_unique_numbers(a1, size1);


    int a2[] = {1, 3, 2, 3, 410, 2, 1, 1, 3, 2};
    int size2 = sizeof(a2)/sizeof(a2[0]);
    cout << unique_in_all_appearing_x_times(a2, size2, 3) << endl;

    return 0;
}

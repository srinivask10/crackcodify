#include <iostream>

using namespace std;

/*
DNF - Dutch National Flag.
Sort array having only 3 elements 0, 1, 2.
Also called 0-1-2 sort.


Divide array in 4 parts.
Zeroes - Ones - Unknowns - Twos

*/

void dnf_sort(int a[], int n)
{
    int l, m, h;
    
    l = 0;
    m = 0;
    h = n - 1;

    while (m <= h)
    {
        if (a[m] == 0)
            swap(a[l++], a[m++]);
        else if (a[m] == 1)
            m++;
        else            //Note: m is not incremented since the swapped m should be checked against 0 also.
            swap(a[m], a[h--]);
    }
}

void printarray(int arr[], int n)
{
    cout << "Array: \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;
}

int main()
{
    int a[] = { 1,0,2,1,1,0,0,0,0 };
    int size = sizeof(a)/sizeof(a[0]);

    printarray(a, size);

    dnf_sort(a, size);

    printarray(a, size);

    return 0;
}

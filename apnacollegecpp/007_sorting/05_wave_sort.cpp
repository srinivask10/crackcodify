#include <iostream>
#include <algorithm>

using namespace std;

/*
Alternating element is less than its neighbouring element.
*/

void wave_sort(int a[], int n)
{
    for (int i = 1; i < n; i+=2)
    {
        if (a[i] > a[i-1])
            swap(a[i], a[i-1]);        
        if (i < n-1 && a[i] > a[i+1])
            swap(a[i], a[i+1]);
    }
}

void printarray(int arr[], int n)
{
    cout << "Array: \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;
}

//O(n/2) = O(n)

int main()
{
    int a[] = { 1,3,4,5,7,6,2 };
    int size = sizeof(a)/sizeof(a[0]);

    printarray(a, size);
    wave_sort(a, size);
    printarray(a, size);

    return 0;
}

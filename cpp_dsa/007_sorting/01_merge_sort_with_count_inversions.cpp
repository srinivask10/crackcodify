#include <iostream>

using namespace std;

/*
If smaller number occurs after bigger one in the array, it is called an inversion.
*/

long long merge(int arr[], int l, int r, int mid)
{
    long long inv = 0;
    int s1, s2, i, j;
    int idx = l;
    
    s1 = mid - l + 1;
    s2 = r - mid;

    int a[s1], b[s2];

    //Copy arrays
    for (int k = 0; k < s1; k++)
        a[k] = arr[l + k];
    for (int k = 0; k < s2; k++)
        b[k] = arr[mid + 1 + k];

    //merge arrays
    i = j = 0;    
    while (i < s1 && j < s2)
    {
        if (a[i] < b[j])
        {
            arr[idx++] = a[i++];
        }
        else
        {
            //a[i], a[i+1], a[i+2], ... a[s1-1] > b[j] since a[] is sorted and  i < j
            inv += (s1 - i);            // **** IMP ****
            arr[idx++] = b[j++];
        }
    }

    while (i < s1)
        arr[idx++] = a[i++];

    while (j < s2)
        arr[idx++] = b[j++];

    return inv;    
}

long long merge_sort(int a[], int l, int r)
{
    long long inv = 0;

    if (l < r)
    {
        int mid = (l + r)/2;

        inv += merge_sort(a, l, mid);
        inv += merge_sort(a, mid+1, r);
        inv += merge(a, l, r, mid);
    }

    return inv;
}

void printarray(int arr[], int n)
{
    cout << "Array: \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;
}

int main()
{
    //int a[] = { 5, 4, 13, 2, 1 };
    int a[] = { 3,5,6,9,1,2,7,8 };
    int size = sizeof(a)/sizeof(a[0]);

    printarray(a, size);

    cout << "Inversions: " << merge_sort(a, 0, size-1) << endl;

    printarray(a, size);

    return 0;
}

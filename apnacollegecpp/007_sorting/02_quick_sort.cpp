#include <iostream>

using namespace std;

int partition(int a[], int l, int r)
{
    int i = l - 1;
    for (int j = l; j <= r-1; j++)
    {
        if (a[j] < a[r])
        {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i+1], a[r]);
    return i+1;
}

void quick_sort(int a[], int l, int r)
{
    if (l >= r)
        return;

    int pivot_idx = partition(a, l, r);
    
    quick_sort(a, l, pivot_idx - 1);
    quick_sort(a, pivot_idx + 1, r);

}

void printarray(int arr[], int n)
{
    cout << "Array: \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;
}

int main()
{
    int a[] = { 5, 4, 13, 2, 1 };
    int size = sizeof(a)/sizeof(a[0]);

    printarray(a, size);

    quick_sort(a, 0, size-1);

    printarray(a, size);

    return 0;
}

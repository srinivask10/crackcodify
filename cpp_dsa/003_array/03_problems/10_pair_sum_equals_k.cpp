//Tell if there exists a pair whose sum is equals k.

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

bool find_pair_sum(int a[], int n, int k)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((a[i] + a[j]) == k)
            {
                cout << i << " " << j << endl;
                return true;
            }
        }
    }

    return false;
}


bool find_pair_sum_by_sorting(int a[], int n, int k)
{
    int sum;
    //first sort the array.
    sort(a, a+n);

    int i = 0, j = n-1;

    while (i < j)
    {
        sum = a[i] + a[j];
        if (sum < k)
        {
            i++;            
        }
        else if (sum > k)
        {
            j--;
        }
        else
        {
            cout << i << " " << j << endl;
            return true;
        }
    }    

    return false;
}


int main()
{
    int k = 31;
    int arr[] = {2,4,7,11,14,16,20,21};

    int size = sizeof(arr)/sizeof(arr[0]);
    
    /*
    int size;
    int arr[size];
    cin >> size;
    cin >> k;
    
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    */

    cout << "brute force method Pair sum present: " <<  find_pair_sum(arr, size, k) << endl;
    cout << "sorting method Pair sum present: " <<  find_pair_sum_by_sorting(arr, size, k) << endl;
    
    return 0;
}

#include <iostream>
#include<algorithm>
#include <climits>
#include <unordered_map>

using namespace std;

/*
    Given an unsorted array of size N of non-negative integers, 
    find a continuous subarray which adds to a given number S.
    Print first and last index of subarray.
*/

int find_sum_of_subarray(int a[], int n, int sum)
{
    int si, sj, subarray_sum, found;

    si = sj = 0;
    found = 0;
    subarray_sum = 0;

    while(sj < n && (subarray_sum+a[sj]) <= sum)
    {
        subarray_sum += a[sj];
        sj++;
    }

    if (subarray_sum == sum)
    {
        cout << si << " " << sj << endl;
        return 1;
    }

    while (sj < n)
    {
        subarray_sum += a[sj];

        while (subarray_sum > sum)
        {
            subarray_sum -= a[si];
            si++;
        }

        if (subarray_sum == sum)
        {
            cout << si << " " << sj << endl;
            return 1;
        }
        sj++;

    }

    return 0;
}

int main()
{
    int size;
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    
    int s;
    cin >> s;

    find_sum_of_subarray(arr, size, s);
    return 0;
}

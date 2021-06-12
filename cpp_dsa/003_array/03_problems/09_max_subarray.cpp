#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

//Time: O(n^3) 
int max_subarray_brute_force(int a[], int n)
{
    int max_sum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += a[k];
            }
            max_sum = max(sum, max_sum);
        }
    }

    return max_sum;
}

//Time: O(n^2) Space: O(n)
int cumulative_subarray_approach(int a[], int n)
{
    int max_sum = INT_MIN;

    int csum[n+1];      //Since we want prev sum to be 0 for [0,0] subarray.
    csum[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        csum[i] = csum[i-1] + a[i-1];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = csum[j+1] - csum[i];
            max_sum = max(sum, max_sum);
        }
    }

    return max_sum;
}



//Time: O(n)
int kadanes_algorithm(int a[], int n)
{
    int max_sum = INT_MIN;

    int csum = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= 0)
            csum += a[i];
        else
            csum = 0;

        max_sum = max(csum, max_sum);
    }

    return max_sum;
}



int circular_subarray_sum(int a[], int n)
{

    int wrap_sum, non_wrap_sum, total_array_sum;

    non_wrap_sum = kadanes_algorithm(a, n);
    total_array_sum = 0;

    for (int i = 0; i < n; i++)
    {
        total_array_sum += a[i];
        a[i] = -a[i];
    }

    wrap_sum = total_array_sum + kadanes_algorithm(a, n );    //total_array_sum - (-kadanes_algorithm(a, n));

    return (max(wrap_sum, non_wrap_sum));

}


int main()
{
    int size;
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    cout << "Brute Force method max sum subarray: " <<  max_subarray_brute_force(arr, size) << endl;
    cout << "Cumulative Sum array method max sum subarray: " <<  cumulative_subarray_approach(arr, size) << endl;
    cout << "Kadanes algorithm Circular max sum subarray: " <<  circular_subarray_sum(arr, size) << endl;

    return 0;
}

#include <iostream>
#include<algorithm>
#include <climits>

using namespace std;

/*
    longest subarray with difference between consecutive numbers in equal.
*/

int get_longest_arithmatic_subarray_size(int arr[], int size)
{
    int prev_diff, curr_diff, cur_len, max_len;

    prev_diff = curr_diff = (arr[1]-arr[0]);
    cur_len = max_len = 2;

    for (int i = 2; i < size; i++)
    {
        curr_diff = (arr[i] - arr[i-1]);
        if (curr_diff == prev_diff)
        {
            cur_len++;
            max_len = max(max_len, cur_len);
        }
        else
        {
            prev_diff = curr_diff;
            cur_len = 2;    
        }
    }  

    return max_len;
}

int main()
{

    int size;
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    
    cout << get_longest_arithmatic_subarray_size(arr, size) << endl;
    return 0;
}

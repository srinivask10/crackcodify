#include <iostream>
#include<algorithm>
#include <climits>

using namespace std;

/*
    Print sum of all subarrays
*/

void print_sum_of_subarrays(int arr[], int size)
{
    cout << "sum of subarrays:" << endl;
    for (int i = 0; i < size; i++)
    {
        int sum = 0;
        for (int j = i; j < size; j++)
        {
            sum += arr[j];
            cout << sum << endl;
        }
    }  
}

int main()
{

    int size;
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    
    print_sum_of_subarrays(arr, size);
    return 0;
}

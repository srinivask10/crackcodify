#include <iostream>
#include<algorithm>
#include <climits>

using namespace std;

/*
    array has visitors for each day. 
    record breaking day is when met following both conditions:
        1. visitor count today is greater than all previous days.
        2. visitor count today is grater than the next day.
    First/Last day can also be a record breaking day.    
    Find total number of record breaking days.
*/

int get_record_breaking_days(int a[], int n)
{
    int highest_visitors_till_now, days;

    if (n == 1)
        return 1;

    highest_visitors_till_now = -1;
    days = 0;

    for (int i = 0; i < n; i++)       //check from 2nd last day.
    {
        if (a[i] > highest_visitors_till_now && (i == n-1 || a[i+1] < a[i]))
        {
            days++;
            highest_visitors_till_now = a[i];
            i++;            //no need to check for next element since it won't be recordbreaking.
        }
    }  

    return days;
}

int main()
{

    int size;
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    
    cout << get_record_breaking_days(arr, size) << endl;
    return 0;
}

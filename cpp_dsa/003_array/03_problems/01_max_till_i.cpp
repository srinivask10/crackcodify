#include <iostream>
#include<algorithm>
#include <climits>

using namespace std;

/*
    Given an array if size n. For every i from 0 to n-1 output max(a[0], a[1], ... a[i])
*/

int main()
{

    int mx = INT_MIN;
    int size;
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
        mx = max(mx, arr[i]);
        cout << mx << endl;
    }
    
    return 0;
}

#include <iostream>
#include<algorithm>
#include <climits>
#include <unordered_map>

using namespace std;

/*
    Find index of first repeating element in an array.
*/

int get_index_of_first_repeating_element(int a[], int n)
{
    int min_idx = INT_MAX;

    unordered_map<int, int> element_index;

    for (int i = 0; i < n; i++)
    {
        auto idx_elem = element_index.find(a[i]);       //save it to avoid second dereference from hash below.
        if (idx_elem == element_index.end())
            element_index[a[i]] = i;
        else
            min_idx = min(idx_elem->second, min_idx);
    }

    if (min_idx == INT_MAX)
        min_idx = -1;
    
    return min_idx;
}

int main()
{
    int size;
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    
    cout << get_index_of_first_repeating_element(arr, size) << endl;
    return 0;
}

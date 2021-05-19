#include <iostream>

using namespace std;

int binary_search(int arr[], int size, int key)
{
    int l, h, mid;

    l = 0;
    h  = size;

    while (l <= h)
    {
        mid = (l+h)/2;
        if (key > arr[mid])
            l = mid+1;
        else if (key < arr[mid])
            h = mid-1;
        else
            return mid;
    }

    return -1;
}

int main()
{
    int size;
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    
    int key;
    cin >> key;

    int loc;

    if ((loc = binary_search(arr, size, key)) != -1)
        cout << "Found at location: " << loc << endl;
    else
        cout << "Not Found" << endl;

}
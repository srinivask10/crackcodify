#include <iostream>

using namespace std;

int linear_search(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
        if (arr[i] == key)
            return i;
    
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

    if ((loc = linear_search(arr, size, key)) != -1)
        cout << "Found at location: " << loc << endl;
    else
        cout << "Not Found" << endl;


}
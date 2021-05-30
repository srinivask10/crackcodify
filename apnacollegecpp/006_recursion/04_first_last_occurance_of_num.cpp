#include <iostream>
#include <algorithm>

using namespace std;

int first_occurance_of_n(int a[], int size, int pos, int n)
{
    if (pos == size)
        return -1;
    
    if (a[pos] == n)
        return pos;

    return first_occurance_of_n(a, size, pos+1, n);

}

int last_occurance_of_n(int a[], int size, int pos, int n)
{

    if (pos == size)
        return -1;

    int rest_pos = last_occurance_of_n(a, size, pos+1, n);
    if (rest_pos != -1)
        return rest_pos;
    
    if (a[pos] == n)
        return pos;

    return -1;

}


int main()
{
    int a[7] = {4, 2, 1, 2, 5, 2, 7};
    cout << first_occurance_of_n(a, 7, 0, 2) << endl;

    int a1[7] = {4, 2, 1, 2, 5, 2, 7};
    cout << last_occurance_of_n(a, 7, 0, 2) << endl;

    return 0;
}

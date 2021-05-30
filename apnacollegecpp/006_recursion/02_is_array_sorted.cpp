#include <iostream>
#include <algorithm>

using namespace std;

bool is_sorted(int a[], int n)
{
    if (n == 1)
        return true;

    if (a[0] < a[1])
        return is_sorted(a+1, n-1);
        
    return false;
}

int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    cout << is_sorted(a, 5) << endl;

    int a1[5] = {1, 2, 3, 14, 5};
    cout << is_sorted(a1, 5) << endl;
    return 0;
}

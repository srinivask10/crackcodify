#include <iostream>
#include <algorithm>

using namespace std;

int euclid_gcd(int a, int b)
{
    int mod;

    if (a < b)
        swap(a, b);

    while ((mod = (a % b)) != 0)
    {
        a = b;
        b = mod;
    }

    return b;
}

int main()
{
    cout << euclid_gcd(30, 45);
    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

/*
Find prime factors using sieve of eratosthenes.

Go on dividing the number using the smallest prime factor of it till the number becomes 1.
We should divide the new number with it's smallest prime factor.

For this we will need to mark all numbers with their smallest prime factor using sieve method.

*/

vector<int> print_prime_factors(int n)
{
    int a[101] = { 0 };

    if (!n)
        return;

    if (n >= 100)
    {
        cout << "Only supported till 100" << endl;
        n = 100;
    }

    //Mark number itself as smallest factor initially.
    for (int i = 1; i <= n; i++)
        a[i] = i;


    //Start marking smallest factors.
    for (int i = 2; i <= n; i++)
    {
        if (i*i > n)        //no need to process further.
            break;

        for (int j = i*i; j <= n; j+=i)
            a[j] = i;
    }

    //Go on dividing numbers till its smallest factor till we go to 1.
    vector<int> prime_factors;
    while (n != 1)
    {
        cout << a[n] << endl;
        prime_factors.push_back(a[n]);
        n = n / a[n];
    }

    return prime_factors;
}

int main()
{
    print_prime_factors(50);
    return 0;
}

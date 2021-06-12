#include <iostream>

using namespace std;

/*
Find prime till N.
Go on marking as non prime for numbers multiple of the number till N.
Start from numbers's square since multiple earlier ones will be marked using earlier numbers.
*/

void print_prime_till_n(int n)
{
    int a[101] = { 0 };

    if (n >= 100)
    {
        cout << "Only supported till 100" << endl;
        n = 100;
    }

    for (int i = 2; i <= n; i++)
    {
        if (i*i > n)        //no need to process further.
            break;

        for (int j = i*i; j <= n; j+=i)
            a[j] = 1;
    }

    for (int i = 2; i <= n; i++)
        if (!a[i])
            cout << i << endl;

}

int main()
{
    print_prime_till_n(50);
    return 0;
}

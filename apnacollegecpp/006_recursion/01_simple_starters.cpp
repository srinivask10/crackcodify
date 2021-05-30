#include <iostream>
#include <algorithm>

using namespace std;


int add_till_n(int n)
{
    return n ? (n + add_till_n(n-1)) : 0;
}

int n_to_power_p(int n, int p)
{
    return p ? (n * n_to_power_p(n, p-1)) : 1;
}

int factorial_of_n(int n)
{
    return n ? (n * factorial_of_n(n-1)) : 1;
}

int nth_fibonacci_number(int n)
{
    return (n == 0 || n == 1) ? n : (nth_fibonacci_number(n-1) + nth_fibonacci_number(n-2));
}


int main()
{

    cout << "Add till : " << add_till_n(13) << endl;
    cout << "n to power p : " << n_to_power_p(3, 4) << endl;
    cout << "factorial of n : " << factorial_of_n(5) << endl;
    cout << "nth fibonacci number: " << nth_fibonacci_number(7) << endl;
    return 0;
}

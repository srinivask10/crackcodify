#include <iostream>

using namespace std;

int get_bit(int n, int pos)
{
    /*
    if (pos > 31)
        return -1;
    */

    return (n & (1 << pos) != 0);
}

int set_bit(int n, int pos)
{
    return (n | (1 << pos));
}

int clear_bit(int n, int pos)
{
    return ((~(1<<pos)) & n);
}

int update_bit(int n, int pos, int bit)
{
    return ( ((~(1 << pos)) & n) | (bit << pos));
}

int is_power_of_2(int n)
{
    return (n && !(n & (n-1)));
}

int main()
{
    cout << "Second bit of 5 is : " << get_bit(5, 2) << endl;
    cout << "Number after setting first bit of 5 is : " << set_bit(5, 1) << endl;
    cout << "Number after clearing second bit of 5 is : " << clear_bit(5, 2) << endl;
    cout << "Number after updating first bit of 5 to 1 is : " << update_bit(5, 1, 1) << endl;
    cout << "Checking is 14 power of 2 : " << is_power_of_2(14) << endl;
    cout << "Checking is 16 power of 2 : " << is_power_of_2(16) << endl;
    return 0;
}


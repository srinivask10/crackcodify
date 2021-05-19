#include <iostream>
#include <string>
using namespace std;


int binary_to_decimal(int n)
{
    int ans = 0;
    int twopower = 1;

    while (n > 0)
    {
        ans += (twopower * (n % 10));
        twopower *= 2;
        n /= 10;
    }

    return ans;
}

int octal_to_decimal(int n)
{
    int ans = 0;
    int eightpower = 1;

    while (n > 0)
    {
        ans += (eightpower * (n % 10));
        eightpower *= 8;
        n /= 10;
    }

    return ans;
}

int hexadecimal_to_decimal(string hex)
{
    int ans = 0;
    int sixteenpower = 1;

    int s = hex.size();
    for (int i = s-1; i >= 0; i--)
    {
        if (hex[i] >= '0' && hex[i] <= '9')
            ans += (sixteenpower * (hex[i] - '0'));
        else if (hex[i] >= 'A' && hex[i] <= 'F')
            ans += (sixteenpower * (hex[i] - 'A' + 10));
        else
        {
            cout << "Invalid hex format";
            return -1;
        }
        sixteenpower *= 16;
    }

    return ans;
}


int decimal_to_binary(int n)
{
    int ans = 0;
    int divider = 1;

    //Find biggest number to start division from.
    while (divider <= n)
        divider *= 2;
    //Remove the extra multiplication.
    divider /= 2;

    //convert
    while (divider > 0)     //Its divider not n. THINK!
    {
        int digit = n / divider;
        ans = (ans * 10) + digit;
        //We should do the minus only if digit is 1.
        n -= (digit * divider);
        divider /= 2;
    }

    return ans;
}

int decimal_to_octal(int n)
{
    int ans = 0;
    int divider = 1;

    //Find biggest number to start division from.
    while (divider <= n)
        divider *= 8;
    //Remove the extra multiplication.
    divider /= 8;

    //convert
    while (divider > 0)     //Its divider not n. THINK!
    {
        int digit = n / divider;
        ans = (ans * 10) + digit;
        //We should do the minus only if digit is 1.
        n -= (digit * divider);
        divider /= 8;
    }

    return ans;
}


string decimal_to_hexadecimal(int n)
{
    string ans = "";
    int divider = 1;
    char ch;

    //Find biggest number to start division from.
    while (divider <= n)
        divider *= 16;
    //Remove the extra multiplication.
    divider /= 16;

    //convert
    while (divider > 0)     //Its divider not n. THINK!
    {
        int digit = n / divider;

        if (digit <= 9)
            ch = digit + '0';
        else
            ch = digit + 'A' - 10;

        ans.push_back(ch);

        //We should do the minus only if digit is 1.
        n -= (digit * divider);
        divider /= 16;
    }

    return ans;
}


int main()
{
    
    int n;
    cin >> n;           //Input based on what you want to call.


    //_TODO_ : Add validations to all functions! So that invalid input will be discarded!

    cout << "Binary [" << n << "] to Decimal [" << binary_to_decimal(n) << "]\n";
    cout << "Octal [" << n << "] to Decimal [" << octal_to_decimal(n) << "]\n";

    string hex;
    cin >> hex;
    cout << "Hexdecimal [" << hex << "] to Decimal [" << hexadecimal_to_decimal(hex) << "]\n";
    

    cout << "Decimal [" << n << "] to Binary [" << decimal_to_binary(n) << "]\n";
    cout << "Decimal [" << n << "] to Octal [" << decimal_to_octal(n) << "]\n";
    cout << "Decimal [" << n << "] to Hexadecimal [" << decimal_to_hexadecimal(n) << "]\n";

    return 0;
}

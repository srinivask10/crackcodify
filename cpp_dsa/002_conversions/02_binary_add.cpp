#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string binary_add(int a, int b)
{
    string ans = "";
    int carry = 0;
    cout << endl;

    while (a > 0 && b > 0) {

        if (a % 2 == 0 && b % 2 == 0) {
            if (carry)
                ans.push_back('1');
            else
                ans.push_back('0');
            carry = 0;
        }
        else if ((a % 2 == 0 && b % 2 == 1) || (a % 2 == 1 && b % 2 == 0)) {
            //no need to update carry. Will be same.
            if (carry)
                ans.push_back('0');
            else
                ans.push_back('1');
        } else {
            ans.push_back('0'+carry);
            carry = 1;      //for case carry was 0.
        }

        a /= 10;
        b /= 10;
    }

    while (a > 0) {
        if (carry) {
            if (a%2 == 1) {
                ans.push_back('1');
            } else {
                ans.push_back('0');
                carry = 0;      //reset carry here.
            }
        } else {
            ans.push_back('0'+(a%2));
            carry = 0;
        }
        a /= 10;
    }


    while (b > 0) {
        if (carry) {
            if (b%2 == 1) {
                ans.push_back('1');
            } else {
                ans.push_back('0');
                carry = 0;      //reset carry here.
            }
        } else {
            ans.push_back('0'+(b%2));
            carry = 0;
        }
        b /= 10;
    }

    if (carry) {
        ans.push_back('0'+carry);
        carry = 0;
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    
    int a, b;
    cin >> a >> b;

    cout << "Addition of binary numbers [" << a << "] and [" << b << "] is [" << binary_add(a, b) << "]\n";

    return 0;
}

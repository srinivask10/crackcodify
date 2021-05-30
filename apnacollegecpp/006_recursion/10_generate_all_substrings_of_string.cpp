#include <iostream>
#include <string>

using namespace std;

string substrings_of_string(string s)
{
    if (s.empty())
    {
        cout << "" << endl;
        return "";
    }

    cout << s[0]+substrings_of_string(s.substr(1));
    cout << substrings_of_string(s.substr(1));
}

int main()
{
    cout << substrings_of_string("abc") << endl;    
    return 0;
}

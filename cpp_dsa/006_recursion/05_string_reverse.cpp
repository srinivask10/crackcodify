#include <iostream>
#include <string>

using namespace std;

void string_reverse(string s)
{
    if (s.empty())
        return;
    string_reverse(s.substr(1));
    cout << s[0] << endl;
}

int main()
{
    string_reverse("srinivas");
    return 0;
}


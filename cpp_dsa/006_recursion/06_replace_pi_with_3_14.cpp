#include <iostream>
#include <string>

using namespace std;

void replace_pi_with_3_14(string s)
{
    if (s.empty())
        return;
    
    if (s[0] == 'p' && s[1] == 'i')
    {
        cout << "3.14";
        replace_pi_with_3_14(s.substr(2));
    }
    else
    {
        cout << s[0];
        replace_pi_with_3_14(s.substr(1));
    }
}

int main()
{
    replace_pi_with_3_14("asdpiasdasdpiasdapia");    
    return 0;
}

#include <iostream>
#include <string>

using namespace std;

static int g_count;

void permutations_of_string(string s, string ans)
{
    if (s.empty())
    {
        cout << ++g_count << " " << ans << endl;
        return;
    }

    for (int i = 0; i < s.length(); i++)    
        permutations_of_string(s.substr(0, i) + s.substr(i+1), ans + s[i]);
    
}

int main()
{
    g_count = 0;
    permutations_of_string("abcd", "");

    
    return 0;
}

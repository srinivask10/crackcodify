#include <iostream>
#include <string>

using namespace std;

static int g_count;

void substrings_of_string(string s, string ans)
{
    if (s.empty())
    {
        cout << g_count++ << " " << ans << endl;
        return;
    }

    substrings_of_string(s.substr(1), ans);
    substrings_of_string(s.substr(1), ans + s[0]);

}

void substrings_of_string_with_ascii(string s, string ans)
{
    if (s.empty())
    {
        cout << g_count++ << " " << ans << endl;
        return;
    }

    int ascii = s[0];
    substrings_of_string_with_ascii(s.substr(1), ans);
    substrings_of_string_with_ascii(s.substr(1), ans + s[0]);
    substrings_of_string_with_ascii(s.substr(1), ans + to_string(ascii));

}

int main()
{
    g_count = 0;
    substrings_of_string("abcd", "");       //O(2^n) (n is length of string)

    g_count = 0;
    substrings_of_string_with_ascii("ABC", ""); //O(3^n) (n is length of string)
    return 0;
}

#include <iostream>
#include <string>

using namespace std;

//Adding space in 0th element to avoid the loop not to proceed for other characters. 
string keypad[] = { " ", "./", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

void print_keypad_possibilities(string keys, string ans)
{
    if (keys.empty())
    {
        cout << ans << endl;
        return;
    }

    for (int i = 0; i < keypad[keys[0]-'0'].length(); i++)
        print_keypad_possibilities(keys.substr(1), ans + keypad[keys[0]-'0'][i]);
}

int main()
{
    print_keypad_possibilities("023", "");
    return 0;
}

#include <iostream>
#include <string>

using namespace std;

string remove_consecutive_duplicates(string s)
{

    if (s.empty())
        return "";

    string ret_s = remove_consecutive_duplicates(s.substr(1));
    if (s[0] == ret_s[0])
        return ret_s;
    return s[0]+ret_s;
}

int main()
{
    cout << remove_consecutive_duplicates("aaaaabbbbccccccccccccdddddddde") << endl;    
    return 0;
}

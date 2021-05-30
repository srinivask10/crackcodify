#include <iostream>
#include <string>

using namespace std;

string move_all_x_to_end(string s)
{
    if (s.empty())
        return "";

    string ret_s = move_all_x_to_end(s.substr(1));
    if (s[0] == 'x')
        return ret_s+'x';
        
    return s[0]+ret_s;
}

int main()
{
    cout << move_all_x_to_end("aaaaaxbbxbbcxxxccccxxxxxxcccxccccxdddddddde") << endl;    
    return 0;
}

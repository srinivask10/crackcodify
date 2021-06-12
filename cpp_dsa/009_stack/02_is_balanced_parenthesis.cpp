#include <iostream>
#include <algorithm>
#include <stack>
#include <math.h>

using namespace std;

bool is_balanced(string s)
{
    stack<char> st;

    for (auto ch : s)
    {
        if (ch == '{' || ch == '[' || ch == '(')
        {
            st.push(ch);
        }
        else if (ch == '}')
        {
            if (st.top() != '{')
                return false;
            st.pop();
        }
        else if (ch == ']')
        {
            if (st.top() != '[')
                return false;
            st.pop();
        }
        else if (ch == ')')
        {
            if (st.top() != '(')
                return false;
            st.pop();
        }
    }

    if (!st.empty())
        return false;

    return true;
}

int main()
{
    cout << is_balanced("{[()]}") << endl;
    cout << is_balanced("{([]}") << endl;

    return 0;
}

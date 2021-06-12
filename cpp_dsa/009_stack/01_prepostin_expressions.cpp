#include <iostream>
#include <algorithm>
#include <stack>
#include <math.h>

using namespace std;

#define PRE 0
#define POST 1

void eval_and_push(const char &expr, const int &op1, const int &op2, stack<int> &st)
{
    switch (expr)
            {
            case '+':
                st.push(op1+op2);
                break;
            
            case '-':
                st.push(op1-op2);
                break;

            case '*':
                st.push(op1*op2);
                break;

            case '/':
                st.push(op1/op2);
                break;
            
            case '%':
                st.push(op1%op2);
                break;
            
            case '^':
                st.push(pow(op1,op2));
                break;
            
            default:
                break;
            }
}

int prepost_eval(string s, int operation)
{
    stack<int> st;

    int start = (operation == PRE) ? s.length() - 1 : 0;
    int end = (operation == PRE) ? -1 : s.length();
    int dir = (operation == PRE) ? -1 : 1;

    for (int i = start; i != end; i += dir)
    {

        int op1, op2;
        
        if (s[i] >= '0' && s[i] <= '9')
        {
            st.push(s[i]-'0');
        }
        else
        {
            op1 = st.top();
            st.pop();
            op2 = st.top();
            st.pop();

            if (operation == POST)
                swap(op1, op2);

            eval_and_push(s[i], op1, op2, st);
        }
    }
    return st.top();
}

int precedence(char op)
{
    switch (op)
    {
    case '^':
        return 3;
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return -1;
    }
}

string infix_to_postfix(string s)
{
    stack<char> st;
    string postfix;
    char tempch;

    for (auto ch : s)
    {
        if (ch == '(')
        {
            st.push(ch);
        }
        else if (ch >= 'a' && ch <= 'z')
        {
            postfix.push_back(ch);
        }
        else if (ch == ')')
        {
            while (!st.empty() && (tempch = st.top()) != '(')
            {
                postfix.push_back(tempch);
                st.pop();
            }
            if (!st.empty())        //pop '('
                st.pop();
        }
        else
        {
            while (!st.empty() && precedence(st.top()) > precedence(ch))
            {
                postfix.push_back(st.top());
                st.pop();
            }
            st.push(ch);
        }
    }

    while(!st.empty())
    {
        postfix.push_back(st.top());
        st.pop();
    }

    return postfix;
}

string infix_to_prefix(string s)
{
    //reverse
    reverse(s.begin(), s.end());

    //convert opening and closing since we reversed the string. Need 1 more level otherwise all will get converted to either ) or (.
    replace( s.begin(), s.end(), '(', '$');
    replace( s.begin(), s.end(), ')', '#');
    replace( s.begin(), s.end(), '$', ')');
    replace( s.begin(), s.end(), '#', '(');

    //get post fix
    s = infix_to_postfix(s);

    //reverse postfix (becomes prefix)
    reverse(s.begin(), s.end());

    return s;
}

int main()
{
    cout << prepost_eval("-+7*45+20", PRE) << endl;
    cout << prepost_eval("46+2/5*7+", POST) << endl;

    cout << infix_to_postfix("(a-b/c)*(a/k-l)") << endl;
    cout << infix_to_prefix("(a-b/c)*(a/k-l)") << endl;

    return 0;
}

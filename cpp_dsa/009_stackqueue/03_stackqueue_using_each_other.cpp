#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

class queue_using_stack
{
    stack <int> s1, s2;
public:
    void enqueue(int n)
    {
        s1.push(n);
    }

    int dequeue()
    {
        if (s1.empty() && s2.empty())
        {
            cout << "Queue empty!" << endl;
            return -1;
        }

        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        int ret = s2.top();
        s2.pop();

        return ret;
    }

    bool is_empty()
    {
        if (s1.empty() && s2.empty())
            return true;
        return false;
    }
};

//Using function call stack
class queue_using_stack2
{
    stack <int> s1;
public:
    void enqueue(int n)
    {
        s1.push(n);
    }

    int dequeue()
    {
        if (s1.empty())
        {
            cout << "Queue empty!" << endl;
            return -1;
        }

        int temp = s1.top();
        s1.pop();
        if (s1.empty())
            return temp;

        int ret = dequeue();
        s1.push(temp);

        return ret;
    }

    bool is_empty()
    {
        if (s1.empty())
            return true;
        return false;
    }
};

//Push heavy operation
class stack_using_queue
{
    queue<int> q1, q2;
public:
    void push(int n)
    {
        if (q1.empty())
        {
            q1.push(n);
        }
        else
        {
            q2.push(n);
            while (!q1.empty())
            {
                q2.push(q1.front());
                q1.pop();
            }
            swap(q1, q2);
        }
    }

    int pop()
    {
        if (q1.empty())
        {
            cout << "Stack is empty!\n";
            return -1;
        }

        int ele = q1.front();
        q1.pop();
        return ele;
    }

    bool is_empty()
    {
        if (q1.empty() && q2.empty())
            return true;
        return false;
    }

    int top()
    {
        if (q1.empty())
        {
            cout << "Stack is empty!\n";
            return -1;
        }
        return q1.front();
    }
};

//Pop heavy operation
class stack_using_queue2
{
    queue<int> q1, q2;
public:
    void push(int n)
    {
        q1.push(n);
    }

    int pop()
    {
        if (q1.empty())
        {
            cout << "Stack is empty!\n";
            return -1;
        }

        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }

        int ele = q1.front();
        q1.pop();

        swap(q1, q2);

        return ele;
    }

    bool is_empty()
    {
        if (q1.empty() && q2.empty())
            return true;
        return false;
    }

    int top()
    {
        if (q1.empty())
        {
            cout << "Stack is empty!\n";
            return -1;
        }

        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }

        int ele = q1.front();
        q1.pop();
        
        q2.push(ele);

        swap(q1, q2);

        return ele;
    }
};


int main()
{
    cout << endl << endl;
    queue_using_stack q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    cout << q.dequeue() << endl;
    q.enqueue(5);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    cout << endl << endl;
    queue_using_stack q2;
    q2.enqueue(1);
    q2.enqueue(2);
    q2.enqueue(3);
    q2.enqueue(4);
    cout << q2.dequeue() << endl;
    q2.enqueue(5);
    cout << q2.dequeue() << endl;
    cout << q2.dequeue() << endl;
    cout << q2.dequeue() << endl;
    cout << q2.dequeue() << endl;
    cout << q2.dequeue() << endl;

    cout << endl << endl;
    stack_using_queue s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();


    cout << endl << endl;
    stack_using_queue2 s2;
    s2.push(1);
    s2.push(2);
    s2.push(3);
    s2.push(4);
    cout << s2.top() << endl;
    s2.pop();
    cout << s2.top() << endl;
    s2.pop();
    cout << s2.top() << endl;
    s2.pop();
    cout << s2.top() << endl;
    s2.pop();
    cout << s2.top() << endl;
    s2.pop();



    return 0;
}

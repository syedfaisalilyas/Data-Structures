#include <iostream>
#include <queue>
using namespace std;

class Stack
{
private:
    int N;
    queue<int> q1;
    queue<int> q2;

public:
    Stack()
    {
        N = 0;
    }

    void push(int x)
    {
        q2.push(x);
        N++;
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }

    void pop()
    {
        if (!q1.empty())
        {
            N--;
            q1.pop();
        }
    }

    int top()
    {
        if (!q1.empty())
        {
            return q1.front();
        }
        return -1; // Stack is empty
    }

    int size()
    {
        return N;
    }
};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout << "Top element: " << s.top() << endl; // Output: 3
    s.pop();
    cout << "Top element after pop: " << s.top() << endl; // Output: 2

    return 0;
}

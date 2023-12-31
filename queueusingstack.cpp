#include <iostream>
#include <stack>
using namespace std;

class Queue {
    stack<int> s1;
    stack<int> s2;

public:
    void push(int x) {
        s1.push(x);
    }

    int pop() {
        if (s1.empty() && s2.empty()) {
            return -1; // Queue is empty
        }

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        int frontValue = s2.top();
        s2.pop();
        return frontValue;
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout << q.pop() << endl; // Output: 1
    cout << q.pop() << endl; // Output: 2

    return 0;
}

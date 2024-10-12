#include<iostream>
#include<stack>
#include<exception>

using namespace std;

class MinStack {
private:
    stack<int> ss, ms;    // ms for saving minumum value
public:
    /** initialize your data structure here. */
    MinStack() {
    }

    void push(int x) {
        ss.push(x);
        if (ms.empty() || ms.top() >= x)
            ms.push(x);
    }

    void pop() {
        if (!ss.empty()) {
            if (ss.top() == ms.top())
                ms.pop();
            ss.pop();
        }
    }

    int top() {
        return ss.top();
    }

    int getMin() {
        return ms.top();
    }
};

int main()
{
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    int minVal = minStack.getMin();
    cout << "Mimimum value on stack is " << minVal << endl;
    minStack.pop();
    int topVal = minStack.top();
    cout << "Top value on stack is " << topVal << endl;
    minVal = minStack.getMin();
    cout << "Mimimum value on stack is " << minVal << endl;
    return 0;
}

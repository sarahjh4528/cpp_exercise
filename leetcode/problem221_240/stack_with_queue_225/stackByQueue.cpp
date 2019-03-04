#include<iostream>
#include<queue>

using namespace std;

class MyStack {
private:
    queue<int> mainQ;
    queue<int> helper;
    int topElem;
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        mainQ.push(x);
        topElem = x;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        while (mainQ.size() > 1) {
            helper.push(mainQ.front());
            mainQ.pop();
        }
        int popElem = mainQ.front();
        mainQ.pop();
        while (helper.size() > 1) {
            mainQ.push(helper.front());
            helper.pop();
        }
        if (!helper.empty()) {
            topElem = helper.front();
            helper.pop();
            mainQ.push(topElem);
        }
        return popElem;
    }
    
    /** Get the top element. */
    int top() {
        return topElem;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return mainQ.empty();
    }
};

int main()
{
    // Your MyStack object will be instantiated and called as such:
    MyStack obj;
#if 0
    obj.push(1);
    obj.push(2);
    obj.push(3);
    obj.push(4);
    obj.push(5);
#endif
    obj.push(1);
    int param_2 = obj.pop();
    cout << "Stack top popped: " << param_2 << endl;
    bool param_4 = obj.empty();
    cout << "Stack empty: " << param_4 << endl;
}

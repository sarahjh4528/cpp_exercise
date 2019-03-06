#include<iostream>
#include<stack>

using namespace std;

class MyQueue
{
private:
    stack<int> mainQ;
    stack<int> helper;
    int frontElem;
public:
     /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if (mainQ.empty())
            frontElem = x;
        mainQ.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while (mainQ.size() > 1) {
            helper.push(mainQ.top());
            mainQ.pop();
        }
        int toPop = mainQ.top();
        mainQ.pop();
        if (!helper.empty())
            frontElem = helper.top();
        while (!helper.empty()) {
            mainQ.push(helper.top());
            helper.pop();
        }
        return toPop;
    }
    
    /** Get the front element. */
    int peek() {
        return frontElem;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return mainQ.empty();
    }
};

int main()
{
/**
 * Your MyQueue object will be instantiated and called as such:
 */
    MyQueue obj;
    obj.push(1);
    obj.push(22);
    obj.push(5);
    obj.push(7);
    
//    obj.push(9);
//    obj.push(10);
    int param_2 = obj.pop();
    cout << "First in " << param_2 << endl;
    cout << "Two more pops " << endl;
    int temp = obj.pop();
    temp = obj.pop();
    int param_3 = obj.peek();
    cout << "Queue front " << param_3 << endl;
    temp = obj.pop();
    bool param_4 = obj.empty();
    cout << "Queue empty:  " << param_4 << endl;
    return 0;
}

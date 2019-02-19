#include<iostream>
#include<vector>
#include<algorithm>
#include<exception>

using namespace std;

struct StackNode
{
    int val;
    StackNode *next;
    StackNode(int x) : val(x), next(NULL) {}
};

class MinStack {
private:
    StackNode *topNode;
    vector<int> sortedList;
    void removeFromSortedList(int val) {
        vector<int>::iterator it;
        for (it = sortedList.begin(); it != sortedList.end(); ++it) {
            if (*it == val)
                break;
        }
        sortedList.erase(it, it + 1);
    }
public:
    /** initialize your data structure here. */
    MinStack(): topNode(NULL) {
        sortedList = {};
    }

    void push(int x) {
        StackNode *newNode = new StackNode(x);
        newNode->next = topNode;
        topNode = newNode;
        sortedList.push_back(x);
        sort(sortedList.begin(), sortedList.end());
    }

    void pop() {
        if (!topNode)
            return;
        StackNode *toDeleteNode = topNode;
        removeFromSortedList(toDeleteNode->val);
        topNode = topNode->next;
        delete toDeleteNode;
    }

    int top() {
        if (topNode)
            return topNode->val;
        else
            throw ("Stack is empty");
    }

    int getMin() {
        if (topNode)
            return sortedList[0];
        else
            throw ("Stack is empty");
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

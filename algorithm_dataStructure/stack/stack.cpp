#include<iostream>

using std::cout;
using std::cerr;
using std::endl;

template<class T>
class Stack
{
private:
    struct StackNode {
        T data;
        StackNode *next;
        StackNode(T newData, StackNode *newNode):data(newData), next(newNode) {};
    };
    StackNode *top;
public:
    void push(const T& obj) {
        StackNode *newNode = new StackNode(obj, top);
        top = newNode;
    }

    T pop() {
        if (!isEmpty()) {
            StackNode *popNode = top;
            top = top->next;
            T retData = popNode->data;
            delete popNode;
            return retData;
        } else {
            cerr << "Stack Empty" << endl;
            return NULL;
        }
    }

    T peek() {
        if (top)
            return top->data;
    }

    bool isEmpty() {
        if (top)
            return false;
        else
            return true;
    }
};

int main()
{
    Stack<int> testStack;
    testStack.push(1);
    testStack.push(2);
    testStack.push(3);
    testStack.push(4);
    testStack.push(5);
    testStack.push(6);

    int stackTop = testStack.peek();
    cout << "Top of stack: " << stackTop << endl;
    return 0;
}


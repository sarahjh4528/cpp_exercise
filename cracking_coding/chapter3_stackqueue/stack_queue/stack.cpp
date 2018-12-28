struct Node
{
    int data;
    Node *next;
    Node(int d):data(d) {}
};

class Stack
{
    Node *top;
    Stack():top(0) {}
    ~Stack() {
        while (top != NULL) {
            int val;
            pop(&val);
        }
    }
    void push(int val) {
        Node *newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    bool pop(int &val) {
        if (top != NULL)
            val = top->data;
        else
            return false;

        Node *t = top;
        top = top->next;
        delete t;
        return true;
    }
}

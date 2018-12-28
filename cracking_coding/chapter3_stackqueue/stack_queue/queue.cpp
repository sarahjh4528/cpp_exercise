struct Node
{
    int data;
    Node *next;
};

class Queue
{
    Node *front, *end;
    void enQueue(int data) {
        if (!front) {
            front = new Node(data);
            end = front;
        } else {
            Node *newNode = new Node(data);
            end->next = newNode;
            end = newNode;
        }
    }

    int deQueue() {
        if (front) {
            Node *toRemove = front;
            front = front->next;
            return toRemove;
        }
    }
    
}

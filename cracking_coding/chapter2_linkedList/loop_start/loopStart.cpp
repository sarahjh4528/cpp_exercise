#include<iostream>

struct Node
{
    int data;
    Node *next;
};

Node *findLoopStart(Node *head)
{
    if (!head || !head->next)
        return NULL;

    Node *slowRunner = head, *fastRunner = head;
    slowRunner = slowRunner->next;
    fastRunner = slowRunner->next;

    while (slowRunner && fastRunner && slowRunner != fastRunner) {
        slowRunner = slowRunner->next;
        if (fastRunner->next)
            fastRunner = fastRunner->next->next;
    }

    if (fastRunner == NULL)    // No loop
        return NULL;

    slowRunner = head;
    while (slowRunner != fastRunner) {
        slowRunner = slowRunner->next;
        fastRunner = fastRunner->next;
    }
    return slowRunner;
}

int main()
{
    return 0;
}

#define NthElement 5

bool find_nthElement(Node *head, Node *nthElement)
{
    if (!head)
        return false;

    // Pass in singly linked list
    Node *theNth = head, *goTail = head;

    int i = 1;
    while (goTail) {
        goTail = goTail->next;
        ++i;
        if (i <= N && goTail == NULL)
            return false;    // Not enough elements.
        if (i == N)
            break;
    }

    if (goTail->next == NULL) {
        nthElement = head;
        return true;
    }

    while (goTail->next) {
        theNth = theNth->next;
        goTail = goTail->next;
    }

    nthElement = theNth;
    return true;
}

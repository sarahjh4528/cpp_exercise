void deleteNode(Node *node)
{
    // Single linked list, pass in node is the one to be deleted. Copy the next node's info into this node.

    if (!node)
        return;

    Node *nextNode = node->next;
    if (nextNode) {
        node->data = nextNode->data;
        node->next = nextNode->next;
    }
}

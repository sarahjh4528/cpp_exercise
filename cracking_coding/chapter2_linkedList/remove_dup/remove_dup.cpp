void delete_duplicate(Node *head)
{
    Node *cur, *prev = head;
    unordered_set<int> node_data_list;
    if (prev) {
        node_data_list.insert(prev->data);
    }

    while (prev->next) {
        cur = prev->next;
        unordered_set<int>::const_iterator found = node_data_list.find(cur->data)
        if (found != node_data_list.end()) {
            // duplicate, remove node. NOTE: cur->next can be null.
            prev->next = cur->next;
        } else {
            node_data_list.insert(cur->data);
        }

        prev = prev->next;
    }
}

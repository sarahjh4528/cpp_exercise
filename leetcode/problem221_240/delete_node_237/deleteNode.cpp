#include<iostream>
#include<vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void printList(ListNode *head) {
        while (head) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }

    ListNode* buildList(vector<int> iv) {
        if (iv.empty())
            return NULL;

        ListNode *head = NULL, *cur = NULL;
        head = new ListNode(iv[0]);
        cur = head;
        for (int i = 1; i < iv.size(); ++i) {
            cur->next = new ListNode(iv[i]);
            cur = cur->next;
        }
        return head;
    }

#if 0
// slow solution: copy entire remaining to one node prev.
    void deleteNode(ListNode* node) {
        while (node->next) {
            node->val = node->next->val;
            if (node->next->next)
                node = node->next;
            else
                break;
        }
        node->next = NULL;
    }
#endif
    void deleteNode(ListNode* node) {
        /* Guarantee 2 nodes, and the given node is not the last */
        node->val = node->next->val;
        ListNode *toDelete = node->next;
        node->next = node->next->next;
        delete toDelete;
    }
};

int main()
{
    vector<int> input = {1,1,2,2,3,4,5,5,6};

    Solution s;
    ListNode *head = s.buildList(input);
    s.printList(head);
    ListNode *toDelete = head;
    while (toDelete->val != 3)
        toDelete = toDelete->next;
    s.deleteNode(toDelete);
    s.printList(head);
    return 0;
}


#include<iostream>
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *front = head, *back = head, *ret = head;
        while (n > 0) {
            front = front->next;
            --n;
        }
        while (front && front->next != NULL) {
            front = front->next;
            back = back->next;
        }
        if (!front && back == head)
            ret = ret -> next;
        else
            back->next = back->next->next;
        return ret;
    }
};

int main() {
    return 0;
}

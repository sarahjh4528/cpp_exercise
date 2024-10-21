/*
Runtime 23 ms Beats 56.54%
Memory 77.46 MB Beats 74.96%
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* head = &dummy,*cur = head;
        int carry = 0, sum = 0;
        while (l1 || l2) {
            sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10;
            sum %= 10;
            cur->next = new ListNode(sum);
            cur = cur->next;
        }
        if (carry)
            cur->next = new ListNode(carry);
        return head->next;
        
    }
};


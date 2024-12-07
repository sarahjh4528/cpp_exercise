/*
Constraints:

The number of nodes in the list is n.
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n

*/
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

/**
 * Definition for singly-linked list
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *buildLinkedList(vector<int> nums) {
        if (nums.size() == 0)
            return NULL;
        ListNode *head = new ListNode(nums[0]);
        ListNode *cur = head;
        for (int i = 1; i < nums.size(); i++) {
            cur->next = new ListNode(nums[i]);
            cur = cur->next;
        }
        return head;
    }

    void printList(ListNode *l) {
        while (l) {
            cout << l->val << " ";
            l = l->next;
        }
        cout << endl;
    }

/*
Runtime 0 ms Beats 100.00%
Memory 11.15 MB Beats 8.83%
*/
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head->next || left == right)
            return head;

        ListNode dummy;
        dummy.next = head;
        ListNode *prev = &dummy;
        for (int i = 1; i < left; i++)
            prev = prev->next;

        ListNode *n1 = prev->next, *n2 = n1->next, *tmp;
        for (int i = 0; i < right - left; i++) {
            tmp = n2->next;
            n2->next = n1;
            n1 = n2;
            n2 = tmp;
        }
        prev->next->next = n2;
        prev->next = n1;
        return dummy.next;
    }
};

int main()
{
    
    Solution s;

    vector<int> input = {...};
    ListNode *head = s.buildLinkedList(input);
    s.printList(head);

    return 0;
}

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
The number of nodes in the linked list is in the range [0, 10^4].
-10^6 <= Node.val <= 10^6
*/
/*
Runtime 0 ms Beats 100.00%
Memory 15.67 MB Beats 29.04%

Time: O(n), Space: O(1)
*/
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next || !head->next->next)
            return head;
        ListNode *cur1 = head, *evenhead = head->next, *cur2 = evenhead;
        while (cur1 && cur2 && cur2->next) {
            cur1->next = cur1->next->next;
            cur2->next = cur2->next->next;
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        cur1->next = evenhead;
        return head;
    }
};

int main()
{
    vector<vector<int>> vlist = {
        {1,2,3,4,5},
        {2,1,3,5,6,4,7}
    };
    Solution s;

    for (auto list : vlist) {
        ListNode *head = s.buildLinkedList(list);
        cout << "Input list: " << endl;
        s.printList(head);
        ListNode *output = s.oddEvenList(head);
        cout << "Output odd even list: " << endl;
        s.printList(output);
    }

    return 0;
}

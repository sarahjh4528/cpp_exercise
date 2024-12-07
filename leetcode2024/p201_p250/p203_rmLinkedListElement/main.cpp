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
Runtime 3 ms Beats 12.31%
Memory 20.35 MB Beats 7.53%

Same solution as fastest. Fastest solution doesn't delete removed elements.
*/
    ListNode* removeElements(ListNode* head, int val) {
        if (!head)
            return NULL;

        ListNode dummy;
        dummy.next = head;
        ListNode *cur = &dummy;
        while (cur->next) {
            if (cur->next->val == val) {
                ListNode *tmp = cur->next;
                cur->next = cur->next->next;
                delete(tmp);
            } else {
                cur = cur->next;
            }
        }
        return dummy.next;
    }
};

int main()
{
    vector<vector<int>> vnums = {
        {1,2,6,3,4,5,6},
        {},
        {7,7,7,7}
    };
    vector<int> vals = {6, 1, 7};
    Solution s;

    for (int i = 0; i < vals.size(); i++) {
        ListNode *head = s.buildLinkedList(vnums[i]);
        s.printList(head);
        ListNode *output = s.removeElements(head, vals[i]);
        s.printList(output);
    }

    return 0;
}

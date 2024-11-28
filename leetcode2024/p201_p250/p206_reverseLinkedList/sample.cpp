/*
Constraints:

The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000
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

    ListNode* reverseList(ListNode* head) {
    }
};

int main()
{
    vector<vector<int>> vn = {
        {1,2,3,4,5},
        {1,2},
        {}
    };
    Solution s;

    for (auto nums : vn) {
        ListNode *head = s.buildLinkedList(nums);
        s.printList(head);
        ListNode *output = s.reverseList(head);
        cout << "After reverse. " << endl;
        s.printList(output);
    }

    return 0;
}

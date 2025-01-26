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
The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000
*/
/*
Runtime 0 ms Beats 100.00%
Memory 13.43 MB Beats 41.24%
*/
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode *p1 = head, *p2 = head->next, *front;
        do {
            front = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = front;
        } while (front);
        head->next = NULL;
        return p1;
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

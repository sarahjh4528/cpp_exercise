/*
Runtime 0 ms Beats 100.00%
Memory 18.06 MB Beats 92.94%
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
    ListNode* merge2Lists(ListNode *l1, ListNode *l2) {
        ListNode dummy;
        ListNode *cur = &dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if (l1)
            cur->next = l1;
        else
            cur->next = l2;
        return dummy.next;
    }

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

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n == 0 || !lists[0])
            return NULL;

        int steps = 1;
        while (steps < n) {
            for (int i = 0; i < n-steps; i += (steps<<1))
                lists[i] = merge2Lists(lists[i], lists[i+steps]);
            steps <<= 1;
        }
        return lists[0];
    }
};

int main()
{
    vector<vector<int>> input = {
        {1,4,5},
        {1,3,4},
        {2,6}
    };
    Solution s;

    vector<ListNode*> vl;
    for (auto v : input) {
        ListNode *head = s.buildLinkedList(v);
        s.printList(head);
        vl.push_back(head);
    }
    ListNode *output = s.mergeKLists(vl);
    s.printList(output);

    return 0;
}

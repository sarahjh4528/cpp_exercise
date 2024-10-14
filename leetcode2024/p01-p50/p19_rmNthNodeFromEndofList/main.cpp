/*
Runtime 4 ms Beats 56.64%
Memory 14.70 MB Beats 76.64%
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

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head)
            return NULL;
        ListNode dummy;
        ListNode *res = &dummy, *prev = &dummy, *p1 = &dummy, *p2 = &dummy;
        res->next = head;
        while (n > 1) {
            p2= p2->next; 
            n--;
        }
        p1 = p1->next;
        p2 = p2->next;
        while (p2->next) {
            prev = prev->next;
            p1 = p1->next;
            p2 = p2->next;
        }
        prev->next = p1->next;
        delete(p1);
        return res->next;
    }
};

int main()
{
    vector<vector<int>> input = {
        {1,2,3,4,5},
        {},
        {1},
        {1,2,3}
    };
    vector<int> vn = {2,1,1,3};
    Solution s;

    for (int i = 0; i < vn.size(); i++) {
        ListNode *head = s.buildLinkedList(input[i]);
        s.printList(head);
        ListNode* output = s.removeNthFromEnd(head, vn[i]);
        s.printList(output);
    }

    return 0;
}

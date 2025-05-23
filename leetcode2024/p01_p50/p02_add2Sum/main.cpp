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
Memory 77.28 MB Beats 12.24%

Time: O(n)
Space: O(1)
*/
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy, *cur = &dummy;
        int carry = 0;
        while (l1 || l2) {
            if (l1) {
                carry += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                carry += l2->val;
                l2 = l2->next;
            }
            cur->next = new ListNode(carry % 10);
            cur = cur->next;
            carry /= 10;
        }
        if (carry)
            cur->next = new ListNode(carry);
        return dummy.next;
    }
};

int main()
{
    vector<vector<int>> vl1 = {
        {2,4,3},
        {0},
        {9,9,9,9,9,9,9}
    };
    vector<vector<int>> vl2 = {
        {5,6,4},
        {0},
        {9,9,9,9}
    };
    Solution s;

    for (int i = 0; i < vl1.size(); i++) {
        ListNode *l1 = s.buildLinkedList(vl1[i]);
        ListNode *l2 = s.buildLinkedList(vl2[i]);
        s.printList(l1);
        s.printList(l2);
        ListNode *output = s.addTwoNumbers(l1, l2);
        cout << "Output: " << endl;
        s.printList(output);
        cout << endl;
    }

    return 0;
}

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
The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
*/
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
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

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
The number of nodes in the list is an even integer in the range [2, 10^5].
1 <= Node.val <= 10^5
*/
/*
Design: Reverse front half of linked list, then traverse from mid to both side

Runtime 0 ms Beats 100.00%
Memory 120.44 MB Beats 95.92%
*/
    int pairSum(ListNode* head) {
        ListNode *prev = NULL, *slow = head, *front = slow->next, *fast = head->next;
        slow->next = prev;
        while (fast && fast->next) {
            prev = slow;
            slow = front;
            front = front->next;
            slow->next = prev;
            fast = fast->next->next;
        }
        int res = 0;
        while (front) {
            res = max(res, (slow->val + front->val));
            slow = slow->next;
            front = front->next;
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> vlist = {
        {5,4,2,1},
        {4,2,2,3},
        {1, 100000}
    };
    Solution s;

    for (auto list : vlist) {
        ListNode *head = s.buildLinkedList(list);
        cout << "Input list: " << endl;
        s.printList(head);
        int output = s.pairSum(head);
        cout << "Max twin sum of linked list: " << output << endl;
    }

    return 0;
}

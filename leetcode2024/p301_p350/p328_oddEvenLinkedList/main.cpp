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
Memory 15.58 MB Beats 63.44%
*/
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next || !head->next->next)
            return head;

        ListNode *evenhead = head->next, *odd = head, *even = evenhead;
        while (odd && even && even->next) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenhead;
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

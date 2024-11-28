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
        cur->next = head->next;
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
Runtime 11 ms Beats 43.81%
Memory 11.91 MB Beats 16.51%

Time : O(N)
Space : O(1)
*/
    bool hasCycle(ListNode *head) {
        if (!head)
            return false;

        ListNode *slow = head;
        ListNode *fast = head->next;
        while (slow != fast) {
            if (fast == NULL || fast->next == NULL)
                return false;
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }

};

int main()
{
    Solution s;

    vector<int> input = {3,2,0,4};
    ListNode *head = s.buildLinkedList(input);
    bool output = s.hasCycle(head);
    cout << "Has cycle: " << output << endl;

    //s.printList(head);

    return 0;
}

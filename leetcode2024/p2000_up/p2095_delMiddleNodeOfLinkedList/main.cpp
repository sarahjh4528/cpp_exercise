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
The number of nodes in the list is in the range [1, 10^5].
1 <= Node.val <= 10^5
*/
/*
Runtime 0 ms Beats 100.00%
Memory 312.10 MB Beats 55.46%
*/
    ListNode* deleteMiddle(ListNode* head) {
        ListNode dummy;
        dummy.next = head;
        ListNode *slow = &dummy, *fast = &dummy;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummy.next;
    }
};

int main()
{
    vector<vector<int>> vlist = {
        {1,3,4,7,1,2,6},
        {1,2,3,4},
        {2,1}
    };
    Solution s;

    for (auto list : vlist) {
        ListNode *head = s.buildLinkedList(list);
        cout << "Orig list: " << endl;
        s.printList(head);
        ListNode *output = s.deleteMiddle(head);
        cout << "After del middle node: " << endl;
        s.printList(output);
    }

    return 0;
}

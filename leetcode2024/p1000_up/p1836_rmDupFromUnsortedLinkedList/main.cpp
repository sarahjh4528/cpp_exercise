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
The number of nodes in the list is in the range [1, 10^5]
1 <= Node.val <= 10^5
*/
/*
Runtime 382 ms Beats 40.95%
Memory 170.52 MB Beats 52.38%

Fastest solution same design

Time: O(n) (2n loop) => O(n)
Space: O(n) (for hash table)
*/
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        if (!head->next)
            return head;

        unordered_map<int, int> nmap;
        ListNode *cur = head;
        while (cur) {
            nmap[cur->val]++;
            cur = cur->next;
        }
        ListNode dummy;
        dummy.next = head;
        ListNode *prev = &dummy, *next = head;
        cur = head;
        while (cur) {
            if (nmap[cur->val] > 1) {
                prev->next = cur->next;
            } else {
                prev = prev->next;
            }
            cur = cur->next;
        }
        return dummy.next;
    }
};

int main()
{
    Solution s;

    vector<vector<int>> input = {
        {1,2,3,2},
        {2,1,1,2},
        {3,2,2,1,3,2,4}
    };
    for (auto nums : input) {
        ListNode *head = s.buildLinkedList(nums);
        s.printList(head);
        ListNode *output = s.deleteDuplicatesUnsorted(head);
        cout << "After rm dup: " << endl;
        s.printList(output);
    }

    return 0;
}

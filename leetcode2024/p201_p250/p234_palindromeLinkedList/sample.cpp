#include<bits/stdc++.h>
#include<iostream>
#include<stack>

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
Constraints:

The number of nodes in the list is in the range [1, 10^5].
0 <= Node.val <= 9
*/
    bool isPalindrome(ListNode* head) {
    }
};

int main()
{
    Solution s;
    vector<vector<int>> input = {
        {1,2,2,1},
        {1,2}
    };

    for (auto nums : input) {
        ListNode *head = s.buildLinkedList(nums);
        s.printList(head);
        bool output = s.isPalindrome(head);
        cout << "Is palindrome: " << output << endl;
    }

    return 0;
}

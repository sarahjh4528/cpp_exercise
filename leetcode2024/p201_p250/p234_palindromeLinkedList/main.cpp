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

#if 0
    bool isPalindrome(ListNode* head) {
        if (!head)
            return true;
        vector<int> v;
        ListNode *cur = head;
        while (cur) {
            v.push_back(cur->val);
            cur = cur->next;
        }
        int l = 0, r = v.size() - 1;
        while (l < r) {
            if (v[l] != v[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
#else
/*
Constraints:

The number of nodes in the list is in the range [1, 10^5].
0 <= Node.val <= 9

Runtime 8 ms Beats 26.50%
Memory 124.91 MB Beats 34.52%

A simpler version is pushing all the elements onto the stack,
Loop through linked list from beginning, compare with stack top element.
*/
    bool isPalindrome(ListNode* head) {
        if (!head->next)
            return true;
        stack<int> st;
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next) {
            st.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast && !fast->next)
            st.push(slow->val);
        slow = slow->next;
        while (slow) {
            if (slow->val != st.top())
                return false;
            slow = slow->next;
            st.pop();
        }
        return true;
    }
#endif
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

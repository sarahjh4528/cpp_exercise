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
Constraints:

k == lists.length
0 <= k <= 10^4
0 <= lists[i].length <= 500
-10^4 <= lists[i][j] <= 10^4
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 10^4.
*/
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    }
};

int main()
{
    vector<vector<int>> input = {
        {1,4,5},
        {1,3,4},
        {2,6}
    };
    Solution s;

    vector<ListNode*> vl;
    for (auto v : input) {
        ListNode *head = s.buildLinkedList(v);
        s.printList(head);
        vl.push_back(head);
    }
    ListNode *output = s.mergeKLists(vl);
    s.printList(output);

    return 0;
}

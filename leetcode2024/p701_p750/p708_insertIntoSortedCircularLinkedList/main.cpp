#include<bits/stdc++.h>
#include<iostream>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};

class Solution {
public:
    Node *buildLinkedList(vector<int> nums) {
        if (nums.size() == 0)
            return NULL;
        Node *head = new Node(nums[0]);
        Node *cur = head;
        for (int i = 1; i < nums.size(); i++) {
            cur->next = new Node(nums[i]);
            cur = cur->next;
        }
        cur->next = head;
        return head;
    }
/*
Runtime 11 ms Beats 9.71%
Memory 12.38 MB Beats 74.89%
Same design as fastest solution
*/

    Node* insert(Node* head, int insertVal) {
        if (!head) {
            Node *newNode = new Node(insertVal);
            newNode->next = newNode;
            return newNode;
        }

        Node *cur = head;
        while (cur->next != head) {
            if (cur->val <= insertVal && insertVal <= cur->next->val)   // prev <= insert <= next
                break;
            else if (cur->val > cur->next->val) {   // Turning point
                if (insertVal >= cur->val || insertVal < cur->next->val) // insert >= biggest || insert <= smallest
                    break;
            }
            cur = cur->next;
        }
        // All numbers are the same in list, insert number is different, Insert anywhere.
        Node *tmp = cur->next;
        cur->next = new Node(insertVal, tmp);
        return head;
    }

};

int main()
{
    vector<vector<int>> input = {
        {3,4,1},
        {},
        {1},
        {1,3,5}
    };
    vector<int> ivals = {2, 1, 0, 1};
    Solution s;

    for (int i = 0; i < ivals.size(); i++) {
        Node *head = s.buildLinkedList(input[i]);
        Node *output = s.insert(head, ivals[i]);
    }

    return 0;
}

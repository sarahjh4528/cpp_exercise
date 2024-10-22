/*
Runtime 3 ms Beats 91.77%
Memory 15.24 MB Beats 19.68%
*/
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)
            return NULL;
        unordered_map<Node*, Node*> map;
        Node *cur = head;
        while (cur) {
            map[cur] = new Node(cur->val);
            cur = cur->next;
        }
        Node *res = map[head];
        cur = head;
        while (cur) {
            map[cur]->random = map[cur->random];
            map[cur]->next = map[cur->next];
            cur = cur->next;
        }
        return res;
        
    }
};

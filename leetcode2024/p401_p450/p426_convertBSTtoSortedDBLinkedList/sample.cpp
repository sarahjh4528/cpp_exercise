/*
Runtime 3 ms Beats 77.19%
Memory 11.78 MB Beats 38.16%
*/
#include<bits/stdc++.h>
#include<iostream>
#include<stack>

using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;
    Node() : val(0), left(nullptr), right(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void printTree(Node *t) {
        if (!t) {
            cout << " null";
            return;
        }
        cout << " " << t->val;
        printTree(t->left);
        printTree(t->right);
    }

    Node* buildTree() {
        Node *top = new Node(4);
        top->left = new Node(2);
        top->right = new Node(5);
        top->left->left = new Node(1);
        top->left->right = new Node(3);
        return top;
    }

    Node* treeToDoublyList(Node* root) {
    }

};

int main()
{
    Solution s;

    Node *root = s.buildTree();
    Node *output = s.treeToDoublyList(root);

    return 0;
}

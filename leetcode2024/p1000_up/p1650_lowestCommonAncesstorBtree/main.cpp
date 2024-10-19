/*
Runtime 13 ms Beats 40.77%
Memory 13.02 MB Beats 81.94%
*/
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;
    Node *parent;
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
        Node *top = new Node(3);
        top->left = new Node(5);
        top->right = new Node(1);
        top->left->left = new Node(6);
        top->left->right = new Node(2);
        top->right->left = new Node(0);
        top->right->right = new Node(8);
        top->left->right->left = new Node(7);
        top->left->right->right = new Node(4);

        return top;
    }

/*
This is variant of "find intersection of 2 linked list"
Starting from 2 pointers, when reaching the end, swap pointer, starting from start.
If == and not nullptr, that's the intersection.

In this case, starting from 2 nodes, going up to root, then swap, when they equal,
that's the commont ancester.
*/
    Node* lowestCommonAncestor(Node* p, Node * q) {
        Node *a = p;
        Node *b = q;
        while (a != b) {
            a = (a->parent == NULL)? q : a->parent;
            b = (b->parent == NULL)? p : b->parent;
        }
        return a;
    }

};

int main()
{
    Solution s;

    Node *root = s.buildTree();
    s.printTree(root);

    T

    return 0;
}

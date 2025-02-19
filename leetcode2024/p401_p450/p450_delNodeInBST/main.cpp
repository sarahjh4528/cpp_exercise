#include<bits/stdc++.h>
#include<iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void printTree(TreeNode *t) {
        if (!t) {
            cout << " null";
            return;
        }
        cout << " " << t->val;
        printTree(t->left);
        printTree(t->right);
    }

    TreeNode* buildTree() {
        TreeNode *top = new TreeNode(5);
        top->left =  new TreeNode(3);
        top->right =  new TreeNode(6);
        top->left->left =  new TreeNode(2);
        top->left->right =  new TreeNode(4);
        top->right->right =  new TreeNode(7);
        return top;
    }

/*
The number of nodes in the tree is in the range [0, 10^4].
-10^5 <= Node.val <= 10^5
Each node has a unique value.
root is a valid binary search tree.
-10^5 <= key <= 10^5
*/
/*
Design:
3 points of rm node in BST
1. In order traversal of BST provides array in ascending order.
2. Node Sucessor: From node right tree, traverse all the way to its left end.
3. Node Predessor: From node left tree, traverse all the way to its right end.

Solution: 3 cases of to be deleted node:
1. If leaf node (no children), delete node.
2. If node has right tree, find sucessor, assign node->val = sucessor->val, delete sucessor node
2. If node has left tree, find predessor, assign node->val = sucessor->val, delete predessor node
*/

    int sucessor(TreeNode *root) {
        while (root->left)
            root = root->left;
        return root->val;
    }

    int predessor(TreeNode *root) {
        while (root->right)
            root = root->right;
        return root->val;
    }

/*
Runtime 0 ms Beats 100.00%
Memory 34.20 MB Beats 93.33%

Time: O(h1 + h2), h1+h2 => log(n) => O(log(n))
Space O(log(n)), O(H), recursion stack
*/
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return NULL;
        if (key < root->val)
            root->left = deleteNode(root->left, key);
        else if (key > root->val)
            root->right = deleteNode(root->right, key);
        else {
            if (!root->left && !root->right) {
                delete root;
                return NULL;
            }
            if (root->right) {
                root->val = sucessor(root->right);
                root->right = deleteNode(root->right, root->val);
            } else {
                root->val = predessor(root->left);
                root->left = deleteNode(root->left, root->val);
            }
        }
        return root;
    }

};

int main()
{
    Solution s;

    TreeNode *root = s.buildTree();
    s.printTree(root);
    cout << endl;
    TreeNode* output = s.deleteNode(root, 3);
    s.printTree(output);
    cout << endl;

    return 0;
}

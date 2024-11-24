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
Runtime 0 ms Beats 100.00%
Memory 33.58 MB Beats 24.75%

Time: O(log(N)) / O(H) H: tree height, in general log(N)
Space : O(H) to keep recursion stack.
*/

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return NULL;
        if (key < root->val)
            root->left = deleteNode(root->left, key);
        else if (key > root->val)
            root->right = deleteNode(root->right, key);
        else {  // root->val == key
            if (!root->left && !root->right) {      // leave node
                delete(root);
                return NULL;
            }
            if (!root->left || !root->right) {      // root has only left or right children
                TreeNode *tmp = (root->left)? root->left : root->right;
                delete(root);
                return tmp;
            }
                
            TreeNode *tmp = root->left;
            while (tmp->right)
                tmp = tmp->right;
            root->val = tmp->val;
            root->left = deleteNode(root->left, tmp->val);
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

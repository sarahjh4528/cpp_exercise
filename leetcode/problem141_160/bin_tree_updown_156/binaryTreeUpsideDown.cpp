/*
 * Given a binary tree where all the right nodes are either leaf nodes with a sibling
 * (a left node that shares the same parent node) or empty, flip it upside down and
 * turn it into a tree where the original right nodes turned into left leaf nodes.
 * Return the new root.
 * 
 * Example:
 * Input: [1,2,3,4,5]
 * 
 *     1
 *    / \
 *   2   3
 *  / \
 * 4   5
 * Output: return the root of the binary tree [4,5,2,#,#,3,1]
 *    4
 *   / \
 *  5   2
 *     / \
 *    3   1
 * Clarification:
 * Confused what [4,5,2,#,#,3,1] means? Read more below on how binary tree is
 * serialized on OJ. The serialization of a binary tree follows a level order
 * traversal, where '#' signifies a path terminator where no node exists below.
 * 
 * Here's an example:
 *    1
 *   / \
 *  2   3
 *     /
 *    4
 *     \
 *      5
 * The above binary tree is serialized as [1,2,3,#,#,4,#,#,5]
 */

/**
 * Definition for a binary tree node.
 */
#include<iostream>
#include<stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *buildTree() {
        TreeNode *root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        root->left->left = new TreeNode(4);
        root->left->right = new TreeNode(5);
        return root;
    }

    void printTree(TreeNode *root) {
        if (!root) {
            cout << " #";
            return;
        }

        cout << " " << root->val;
        printTree(root->left);
        printTree(root->right);
    }

    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (!root || (!root->left && !root->right))
            return root;

        stack<TreeNode *> treeSt;
        while (root->left) {
            treeSt.push(root);
            root = root->left;
        }
        TreeNode* newRoot = root, *cur = root;
        while (!treeSt.empty()) {
            TreeNode *node = treeSt.top();
            cout << node->val << endl;
            treeSt.pop();
            cur->left = node->right;
            cur->right = node;
            node->left = NULL;
            node->right = NULL;
            cur = cur->right;
        }
        return newRoot;
    }
};

int main() {
    Solution s;
    TreeNode *root = s.buildTree();
    TreeNode *upsideDownRoot = s.upsideDownBinaryTree(root);
    s.printTree(upsideDownRoot);
    return 0;
}

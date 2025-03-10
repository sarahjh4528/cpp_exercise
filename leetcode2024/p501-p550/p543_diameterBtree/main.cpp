/*
Runtime 0 ms Beats 100.00%
Memory 22.28 MB Beats 95.92%
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int solve(TreeNode *root, int& res) {
        if (!root)
            return 0;
        int left = solve(root->left, res);
        int right = solve(root->right, res);
        res = max(res, left+right);
        return 1 + max(left, right);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        solve(root, res);
        return res;
    }
};


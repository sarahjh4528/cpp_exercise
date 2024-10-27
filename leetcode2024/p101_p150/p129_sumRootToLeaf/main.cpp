/*
Runtime 0 ms Beats 100.00%
Memory 11.18 MB Beats 86.12%
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
    void dfs(TreeNode* root, int curSum, int& res) {
        if (!root->left && !root->right) {
            res += (curSum * 10 + root->val);
            return;
        }
        curSum = curSum * 10 + root->val;
        if (root->left)
            dfs(root->left, curSum, res);
        if (root->right)
            dfs(root->right, curSum, res);

    }
public:
    int sumNumbers(TreeNode* root) {
        int res = 0;
        dfs(root, 0, res);
        return res;
    }
};


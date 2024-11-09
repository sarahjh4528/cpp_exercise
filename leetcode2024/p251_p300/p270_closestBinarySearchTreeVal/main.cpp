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
    void solve(TreeNode* root, double target, int& res) {
        if (!root)
            return;
        double curdiff = abs(target - (double)root->val);
        double lastdiff = abs(target - (double)res);
        if ((curdiff == lastdiff && root->val < res) ||
            curdiff < lastdiff)
            res = root->val;
        if (root->val < target)         // skip left tree
            solve(root->right, target, res);
        else if (root->val > target)    // skip left tree
            solve(root->left, target, res);
    }
public:
/*
Runtime 0 ms Beats 100.00%
Memory 19.77 MB Beats 33.36%
*/
    int closestValue(TreeNode* root, double target) {
        int res = root->val;
        solve(root, target, res);
        return res;
    }
};

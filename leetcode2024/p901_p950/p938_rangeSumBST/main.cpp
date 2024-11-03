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

/*
Runtime 0 ms Beats 100.00%
Memory 63.29 MB Beats 66.86%
*/
class Solution {
    void dfs(TreeNode* root, int low, int high, int& res) {
        if (!root)
            return;
        if (root->val >= low && root->val <= high)
            res += root->val;
        dfs(root->left, low, high, res);
        dfs(root->right, low, high, res);
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int res = 0;
        dfs(root, low, high, res);
        return res;
    }
#if 0
Sample fastest code
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
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root == NULL) return 0;
        int left = rangeSumBST(root->left, low, high);
        int right = rangeSumBST(root->right, low, high);
        if(root->val >= low && root->val <= high){
            return root->val + left+right;
        }
        return left+right;
    }
};
#endif

};

int main()
{
    Solution s;

    TreeNode *root = s.buildTree();
    s.printTree(root);

    return 0;
}

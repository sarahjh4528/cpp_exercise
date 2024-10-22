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
/*
Runtime 12 ms Beats 96.41%
Memory 66.10 MB Beats 5.49%
*/
    void dfs(TreeNode *root, stack<TreeNode*>& st, int high) {
        if (!root)
            return;
        dfs(root->left, st, high);
        if (root->val > high)
            return;
        st.push(root);
        dfs(root->right, st, high);
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        stack<TreeNode*> st;
        dfs(root, st, high);
        int sum = 0;
        bool inRange = false;
        while (!st.empty()) {
            TreeNode *cur = st.top();
            st.pop();
            if (cur->val >= low)
                sum += cur->val;
        }
        return sum;
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

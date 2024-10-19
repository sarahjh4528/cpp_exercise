/*
Runtime 4 ms Beats 59.50%
Memory 16.62 MB Beats 5.23%

TODO: Fastest solution is to utilize a queue,
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
    void dfs(TreeNode* root, int key, int level, map<int, vector<vector<int>>>& vmap) {
        if (!root)
            return;
        if (vmap[key].size() < level+1)
            vmap[key].resize(level+1);
        vmap[key][level].push_back(root->val);
        dfs(root->left, key-1, level+1, vmap);
        dfs(root->right, key+1, level+1, vmap);
    }
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root)
            return res;

        map<int, vector<vector<int>>> vmap;
        dfs(root, 0, 0, vmap);
        for (auto it = vmap.begin(); it != vmap.end(); it++) {
            vector<int> tmp;
            for (auto vn : it->second)
                tmp.insert(tmp.end(), vn.begin(), vn.end());
            res.push_back(tmp);
        }

        return res;
    }
};


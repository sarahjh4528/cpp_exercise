/*
Runtime 4 ms Beats 63.61%
Memory 15.41 MB Beats 50.37%

Fastest solution uses DFS (recursion) to create parent map, might be faster.
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> pmap;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int qsize = q.size();
            for (int i = 0; i < qsize; i++) {
                TreeNode* cur = q.front();
                q.pop();
                if (cur->left) {
                    pmap[cur->left] = cur;
                    q.push(cur->left);
                }
                if (cur->right) {
                    pmap[cur->right] = cur;
                    q.push(cur->right);
                }
            }
        }
        unordered_map<TreeNode*, bool> visited;
        q.push(target);
        visited[target] = true;
        int level = 0;
        while (!q.empty()) {
            if (level == k)
                break;
            level++;
            int qsize = q.size();
            for (int i = 0; i < qsize; i++) {
                TreeNode* cur = q.front();
                q.pop();
                if (cur->left && !visited[cur->left]) {
                    visited[cur->left] = true;
                    q.push(cur->left);
                }
                if (cur->right && !visited[cur->right]) {
                    visited[cur->right] = true;
                    q.push(cur->right);
                }
                if (pmap[cur] && !visited[pmap[cur]]) {
                    visited[pmap[cur]] = true;
                    q.push(pmap[cur]);
                }
            }
        }
        vector<int> res;
        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            res.push_back(cur->val);
        }
        return res;
    }
};

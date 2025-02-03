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
    unordered_map<long, int> tmap;
    void dfs(TreeNode *root, int target, long curSum, int& cnt) {
        if (!root) return;
        curSum += root->val;
        if (tmap.count(curSum - target))
            cnt += tmap[curSum - target];
        tmap[curSum]++;
        dfs(root->left, target, curSum, cnt);
        dfs(root->right, target, curSum, cnt);
        tmap[curSum]--;
    }

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
        TreeNode *top = new TreeNode(10);
        top->left = new TreeNode(5);
        top->right = new TreeNode(-3);
        top->left->left = new TreeNode(3);
        top->left->right = new TreeNode(2);
        top->left->left->left = new TreeNode(3);
        top->left->left->right = new TreeNode(-2);
        top->left->right->right = new TreeNode(1);
        top->right->right = new TreeNode(11);
        return top;
    }

/*
The number of nodes in the tree is in the range [0, 1000].
-10^9 <= Node.val <= 10^9
-1000 <= targetSum <= 1000
*/
/*
Runtime 4 ms Beats 82.60%
Memory 20.61 MB Beats 40.67%

Time: O(n), Space: O(n)
*/
    int pathSum(TreeNode* root, int targetSum) {
        int res = 0;
        tmap[0] = 1;
        dfs(root, targetSum, 0, res);
        return res;
    }

};

int main()
{
    Solution s;
    int targetSum = 8;

    TreeNode *root = s.buildTree();
    s.printTree(root);
    cout << endl;

    int output = s.pathSum(root, targetSum);
    cout << "Num of paths sum to " << targetSum << " : " << output << endl;
    return 0;
}

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

/*
Design: dynamic programming
dp(0) : 0
dp(1) : 1
dp(2) : 2
for (int i = 2; i <= n; i++)
i = 2: j (1, 2)
if j == 1, left tree has no node, right tree has 1 node
if j == 2, left tree has one node, right tree has 0 node
Total : 1 + 1 = 2

i = 3: j (1,2,3),
j = 1, left tree has 0 node, right tree has 2 nodes, 1 * 2 = 2 trees, dp[j-1]*dp[i-j]
j = 2, left tree has 1 node, right tree has 1 node, 1 * 1 = 1 tree, dp[j-1]*dp[i-j]
j = 3, left tree has 2 nodes, right tree has 1 node, 2 * 1 = 2 trees, dp[j-1]*dp[i-j]
Total : 2 + 1 + 1 = 5

i = 4: j (1,2,3,4)
j = 1, left tree has 0 node, right tree has 3 nodes, 1 * 5 = 5 trees
j = 2, left tree has 1 node, right tree has 2 nodes, 1 * 2 = 2 trees
j = 3, left tree has 2 node, right tree has 1 nodes, 2 * 1 = 2 trees
j = 4, left tree has 3 node, right tree has 0 nodes, 5 * 1 = 5 trees
Total : 5 + 2 + 2 + 5 = 14

Runtime 0 ms Beats 100.00%
Memory 8.13 MB Beats 5.08%

Time: O(N), Space : O(N)
*/
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;      // root == NULL
        dp[1] = 1;      // root == 1st node
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[j-1]*dp[i-j];
            }
        }
        return dp[n];
    }

};

int main()
{
    vector<int> vn = {3, 1};
    Solution s;

    for (auto n : vn) {
        int output = s.numTrees(n);
        cout << "Num of unique trees with " << n  << " nodes : " << output << endl;
    }

    return 0;
}

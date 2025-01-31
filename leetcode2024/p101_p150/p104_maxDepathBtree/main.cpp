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

    TreeNode* buildTree() {
        TreeNode *top = new TreeNode(3);
        top->left = new TreeNode(9);
        top->right = new TreeNode(20);
        top->right->left = new TreeNode(15);
        top->right->right = new TreeNode(7);
        return top;
    }

/*
The number of nodes in the tree is in the range [0, 10^4].
-100 <= Node.val <= 100
*/
/*
Runtime 0 ms Beats 100.00%
Memory 19.26 MB Beats 13.45%

Time: O(N), Space: O(N)
*/
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        int res = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            res++;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode *cur = q.front();
                q.pop();
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
        }
        return res;
    }
};

int main()
{
    Solution s;

    TreeNode *root = s.buildTree();
    s.printTree(root);
    cout << endl;

    int output = s.maxDepth(root);
    cout << "Max depth of tree: " << output << endl;

    return 0;
}

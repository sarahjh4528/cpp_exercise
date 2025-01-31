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
Solution 1: DFS or BFS
Solution 2: Recursion (TODO)
*/
    int maxDepth(TreeNode* root) {
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

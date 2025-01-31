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

#if 0
    TreeNode* buildTree1() {
        TreeNode *top = new TreeNode(3);
        top->left = new TreeNode(5);
        top->right = new TreeNode(1);
        top->left->left = new TreeNode(6);
        top->left->right = new TreeNode(2);
        top->right->left = new TreeNode(9);
        top->right->right = new TreeNode(8);
        top->left->right->left = new TreeNode(7);
        top->left->right->right = new TreeNode(4);
        return top;
    }

    TreeNode* buildTree2() {
        TreeNode *top = new TreeNode(3);
        top->left = new TreeNode(5);
        top->right = new TreeNode(1);
        top->left->left = new TreeNode(6);
        top->left->right = new TreeNode(7);
        top->right->left = new TreeNode(4);
        top->right->right = new TreeNode(2);
        top->right->right->left = new TreeNode(9);
        top->right->right->right = new TreeNode(8);
        return top;
    }
#else
    TreeNode* buildTree1() {
        TreeNode *top = new TreeNode(1);
        top->left = new TreeNode(2);
        top->right = new TreeNode(3);
        return top;
    }

    TreeNode* buildTree2() {
        TreeNode *top = new TreeNode(1);
        top->left = new TreeNode(3);
        top->right = new TreeNode(2);
        return top;
    }
#endif

    void dfs(TreeNode *root, vector<int>& v) {
        if (!root)
            return;
        if (!root->left && !root->right) {
            v.push_back(root->val);
            return;
        }
        dfs(root->left, v);
        dfs(root->right, v);
    }

/*
The number of nodes in each tree will be in the range [1, 200].
Both of the given trees will have values in the range [0, 200].
*/
/*
Runtime 0 ms Beats 100.00%
Memory 15.37 MB Beats 32.40%

Time: O(m+n), Space O(m+n)
*/
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> l1, l2;
        dfs(root1, l1);
        dfs(root2, l2);
        return (l1 == l2);
    }
};

int main()
{
    Solution s;

    TreeNode *root1 = s.buildTree1();
    s.printTree(root1);
    cout << endl;
    TreeNode *root2 = s.buildTree2();
    s.printTree(root2);
    cout << endl;

    bool output = s.leafSimilar(root1, root2);
    cout << "Leaf similar tree: " << output << endl;

    return 0;
}

#include<iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *buildTree() {
        TreeNode *top = new TreeNode(6);
        top->left = new TreeNode(2);
        top->right = new TreeNode(8);
        top->left->left = new TreeNode(0);
        top->left->right = new TreeNode(4);
        top->right->left = new TreeNode(7);
        top->right->right = new TreeNode(9);
        top->left->right->left = new TreeNode(3);
        top->left->right->right = new TreeNode(5);
        return top;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return NULL;
        if (root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);
        else if (root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        else
            return root;
    }
};
int main()
{
    Solution s;

    TreeNode *top = s.buildTree();
    TreeNode *p = new TreeNode(2);
    TreeNode *q = new TreeNode(4);
    TreeNode *acNode = s.lowestCommonAncestor(top, p, q);
    if (acNode)
        cout << acNode->val << endl;
    return 0;
}

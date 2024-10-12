#include<iostream>
#include<vector>
#include<deque>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int i): val(i), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode* buildSymmetricTree(vector<int> vals) {
        TreeNode *top = new TreeNode(vals[0]);
        deque<TreeNode *> treeTopQueue;
        treeTopQueue.push_back(top);
        int i = 1;
        while (!treeTopQueue.empty() && i < vals.size()) {
            TreeNode *subTop = treeTopQueue.front();
            treeTopQueue.pop_front();
            subTop->left = new TreeNode(vals[i]);
            treeTopQueue.push_back(subTop->left);
            ++i;
            subTop->right = new TreeNode(vals[i]);
            treeTopQueue.push_back(subTop->right);
            ++i;
        } 
        return top;
    }

    bool isSameNodes(TreeNode *n1, TreeNode *n2) {
        if (n1 == NULL && n2 == NULL)
            return true;

        if (!n1 || !n2 || n1->val != n2->val)
            return false;

        return (isSameNodes(n1->right, n2->left) && isSameNodes(n1->left, n2->right));
    }

    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;

        return isSameNodes(root->left, root->right);
    }
};

int main()
{
    Solution s;
#if 0
    vector<int> sTreeVals = {1,2,2,3,4,4,3};
    TreeNode *top = s.buildSymmetricTree();
    TreeNode *top = s.buildASymmetricTree();
#endif
    vector<int> sTreeVals = {1,2,2,3,4,4,3};
    TreeNode *top = s.buildSymmetricTree(sTreeVals);
    bool isSym = s.isSymmetric(top);
    cout << "Is symmetric: " << isSym << endl;

    return 0;
}

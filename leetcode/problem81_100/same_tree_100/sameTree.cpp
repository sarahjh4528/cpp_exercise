#include<iostream>
#include<vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode* buildLTree(vector<int> vals) {
        TreeNode *top = new TreeNode(vals[0]);
        TreeNode *leftNode = new TreeNode(vals[1]);
        top->left = leftNode;
        return top;
    }

    TreeNode* buildRTree(vector<int> vals) {
        TreeNode *top = new TreeNode(vals[0]);
        TreeNode *rightNode = new TreeNode(vals[1]);
        top->right = rightNode;
        return top;
    }

    TreeNode* buildTree(vector<int> vals) {
        TreeNode *top = new TreeNode(vals[0]);
        TreeNode *leftNode = new TreeNode(vals[1]);
        TreeNode *rightNode = new TreeNode(vals[2]);
        top->left = leftNode;
        top->right = rightNode;
        return top;
    }

    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p == NULL && q == NULL)
            return true;
        else if ((p && !q) || (q && !p))
            return false;

        if (p->val != q->val)
            return false;

        if (!isSameTree(p->left, q->left))
            return false;

        if (!isSameTree(p->right, q->right))
            return false;

        return true;
    }
};

int main()
{
#if 0
    vector<int> t1 = {1,2,3};
    vector<int> t2 = {1,2,3};

    vector<int> t1 = {1,2,1};
    vector<int> t2 = {1,1,2};
    TreeNode *tree1 = s.buildTree(t1);
    TreeNode *tree2 = s.buildTree(t2);

    vector<int> t1 = {1,2};
    vector<int> t2 = {1,2};
    TreeNode *tree1 = s.buildLTree(t1);
    TreeNode *tree2 = s.buildRTree(t2);
#endif
    Solution s;
    vector<int> t1 = {1,2,3};
    vector<int> t2 = {1,2,3};
    TreeNode *tree1 = s.buildTree(t1);
    TreeNode *tree2 = s.buildTree(t2);

    bool sameTree = s.isSameTree(tree1, tree2);
    cout << "Same tree : " << sameTree << endl;
    return 0;
}

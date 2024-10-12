#include<iostream>
#include<vector>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    void printVals(vector<vector<int>> &vals) {
        for (auto level : vals) {
            for (int i = 0; i < level.size(); ++i)
                cout << level[i] << " ";
            cout << endl;
        }
        cout << endl;
    }

    TreeNode *buildTree() {
        TreeNode *top = new TreeNode(3);
        top->left = new TreeNode(9);
        top->right = new TreeNode(20);
        top->right->left = new TreeNode(15);
        top->right->right = new TreeNode(7);
        return top;
    }

    int getTreeMaxDepth(TreeNode *root) {
        if (!root)
            return 0;
        return (max(getTreeMaxDepth(root->left), getTreeMaxDepth(root->right)) + 1);
    }

    void levelOrderBottonWithLevel(TreeNode *root, int level, vector<vector<int>> &vals) {
        if (!root)
            return;

        vals[vals.size() - 1 - level].push_back(root->val);
        levelOrderBottonWithLevel(root->left, level + 1, vals);
        levelOrderBottonWithLevel(root->right, level + 1, vals);
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root)
            return {};
        int treeDepth = getTreeMaxDepth(root);

        // Preallocate vector, and initialize each level with an empty vector
        // This make the program runs much faster.
        vector<vector<int>> nodeVals(treeDepth, vector<int> {}); 
        levelOrderBottonWithLevel(root, 0, nodeVals);
        return nodeVals;
    }
};

int main()
{
    Solution s;

    TreeNode *top = s.buildTree();
    vector<vector<int>> nodeVals = s.levelOrderBottom(top);
    s.printVals(nodeVals);
    return 0;
}

#include<iostream>
#include<vector>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode* buildTree() {
        TreeNode *top = new TreeNode(3);
        top->left = new TreeNode(9);
        top->right = new TreeNode(20);
        top->right->left = new TreeNode(15);
        top->right->right = new TreeNode(7);
        return top;
    }

    void printTree(TreeNode *top) {
        if (!top)
            return;

        printTree(top->left);
        cout << top->val << " ";
        printTree(top->right);
    }

    void getMaxHeight(TreeNode *root, int& height) {
        if (!root)
            return;

        height += 1;
        int lHeight = height, rHeight = height;
        getMaxHeight(root->left, lHeight);
        getMaxHeight(root->right, rHeight);
        height = max(lHeight, rHeight);
    }

    void getLevelOrder(TreeNode *root, int level, vector<vector<int>>& orders) {
        if (!root)
            return;

        orders[level].push_back(root->val);
        getLevelOrder(root->left, level + 1, orders);
        getLevelOrder(root->right, level + 1, orders);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        int maxH = 0;
        getMaxHeight(root, maxH);

        vector<vector<int>> ret(maxH, vector<int>{});
        getLevelOrder(root, 0, ret);
        return ret;
    }
};

int main()
{
    Solution s;
    TreeNode *treeTop = s.buildTree();
    s.printTree(treeTop);
    cout << endl;

    vector<vector<int>> lorders = s.levelOrder(treeTop);
    cout << "return vector size: " << lorders.size() << endl;
    return 0;
}

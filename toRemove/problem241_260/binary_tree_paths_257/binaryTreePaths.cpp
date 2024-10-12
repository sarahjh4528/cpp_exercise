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
    TreeNode *buildTree() {
        TreeNode *top = new TreeNode(3);
        top->left = new TreeNode(9);
        top->right = new TreeNode(20);
        top->right->left = new TreeNode(15);
        top->right->right = new TreeNode(7);
        return top;
    }

    void getTreePaths(TreeNode *root, vector<string> &strList) {
        if (!root)
            return;
        if (!root->left && !root->right) {
            strList.push_back(to_string(root->val));
            return;
        }
        vector<string> lList, rList;
        getTreePaths(root->left, lList);
        getTreePaths(root->right, rList);
        for (int i = 0; i < lList.size(); ++i) {
            lList[i] = to_string(root->val) + "->" + lList[i];
        }
        for (int i = 0; i < rList.size(); ++i) {
            rList[i] = to_string(root->val) + "->" + rList[i];
        }
        strList.insert(strList.end(), lList.begin(), lList.end());
        strList.insert(strList.end(), rList.begin(), rList.end());
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> strList;
        getTreePaths(root, strList);
        return strList; 
    }
};

int main()
{
    Solution s;

    TreeNode *top = s.buildTree();
    vector<string> treePaths = s.binaryTreePaths(top);
    for (auto str : treePaths)
        cout << str << endl;
    return 0;
}

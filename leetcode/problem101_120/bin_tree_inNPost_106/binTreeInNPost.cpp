/**
 * Definition for a binary tree node.
 * Given inorder and postorder traversal of a tree, construct the binary tree.
 * inorder = [9,3,15,20,7]
 * postorder = [9,15,7,20,3]
 */
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    TreeNode* buildTreeWithIndex(vector<int>& inorder, int iStart, int iEnd,
                                 vector<int>& postorder, int pStart, int pEnd) {
        if (iStart >= iEnd && pStart >= pEnd)
            return NULL;

        TreeNode *root = new TreeNode(postorder[pEnd-1]);

        auto it = find(inorder.begin()+iStart, inorder.begin()+iEnd, root->val);
        int leftTreeNodes = it - inorder.begin() - iStart;
        root->left = buildTreeWithIndex(inorder, iStart, iStart+leftTreeNodes,
                                        postorder, pStart, pStart+leftTreeNodes);
        root->right = buildTreeWithIndex(inorder, iStart+1+leftTreeNodes, iEnd,
                                         postorder, pStart+leftTreeNodes, pEnd-1);
        return root;
    }
public:
    void printTree(TreeNode *top) {
        if (!top)
            return;

        printTree(top->left);
        cout << top->val << " ";
        printTree(top->right);
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTreeWithIndex(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
};

int main()
{
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};

    Solution s;
    TreeNode* root = s.buildTree(inorder, postorder);

    cout << "Print tree inorder" << endl;
    s.printTree(root);
    cout << endl;
    return 0;
}


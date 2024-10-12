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

class Solution
{
public:
    void printTree(TreeNode *top) {
        if (!top)
            return;
        printTree(top->left);
        cout << top->val << " ";
        printTree(top->right);
    }
    TreeNode* buildTreeWithIndex(vector<int>& preorder, int pStart, int pEnd,
                                 vector<int>& inorder, int iStart, int iEnd) {
        if (pStart >= pEnd && iStart >= iEnd) {
            return NULL;
        }
        TreeNode *root = new TreeNode(preorder[pStart]);
        vector<int>::iterator it = find(inorder.begin()+iStart,
                                        inorder.begin()+iEnd,
                                        preorder[pStart]);
        int leftNodes = it - inorder.begin() - iStart;
        root->left = buildTreeWithIndex(preorder, pStart+1, pStart+1+leftNodes,
                                        inorder, iStart, iStart+leftNodes);
        root->right = buildTreeWithIndex(preorder, pStart+1+leftNodes, pEnd,
                                        inorder, iStart+1+leftNodes, iEnd);
        return root;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeWithIndex(preorder, 0, preorder.size(),
                                  inorder, 0, inorder.size());
    }
};

int main()
{
    vector<int> preVec = {3,9,20,15,7};
    vector<int> inVec = {9,3,15,20,7};
    Solution s;
    TreeNode *top = s.buildTree(preVec, inVec);
    cout << "Print tree in order. " << endl;
    s.printTree(top);
    return 0;
}

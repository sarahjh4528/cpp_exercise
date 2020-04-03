/**
 * Binary tree node
 * Recursive solution: Faster than 100%, memory less than 72%.
 * Loop solution : Faster than 100%, memory less than 11%.
 */
#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *buildTree1() {
        TreeNode *top = new TreeNode(10);
        top->left = new TreeNode(5);
        top->right = new TreeNode(15);
        return top;
    }

    TreeNode *buildTree2() {
        TreeNode *top = new TreeNode(10);
        top->left = new TreeNode(5);
        return top;
    }
#if 0
    // Recursive solution
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q)
            return true;

        if (!p || !q)
            return false;

        if (p->val != q->val)
            return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
#endif
    // Loop
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q)
            return true;

        if (!p || !q)
            return false;
        stack<TreeNode *> pSt, qSt;
        pSt.push(p);
        qSt.push(q);
        while (!pSt.empty() || !qSt.empty()) {
            if (pSt.empty() || qSt.empty())
                return false;
            while (p->left && q->left) {
                pSt.push(p->left);
                qSt.push(q->left);
                p = p->left;
                q = q->left;
            }
            if (p->left || q->left)
                return false;

            TreeNode *pNode = pSt.top();
            TreeNode *qNode = qSt.top();
            pSt.pop();
            qSt.pop();
            if (pNode->val != qNode->val)
                return false;
            if (pNode->right && qNode->right) {
                pSt.push(pNode->right);
                qSt.push(qNode->right);
                p = pNode->right;
                q = qNode->right;
            } else if (pNode->right || qNode->right) {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    TreeNode *t1 = s.buildTree1();
    TreeNode *t2 = s.buildTree2();
    bool isSame = s.isSameTree(t1, t2);
    cout << "Same tree: " << isSame << endl;
        
    return 0;
}

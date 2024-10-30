/*
Runtime 2 ms Beats 75.48%
Memory 30.70 MB Beats 6.30%
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct Node {
    int val;
    Node *next;
    Node (int x) : val(x), next(nullptr) {}
};
class BSTIterator {
    Node *dummy, *cur;
    void inorder(TreeNode *root) {
        if (!root)
            return;
        inorder(root->left);
        cur->next = new Node(root->val);
        cur = cur->next;
        inorder(root->right);
    }
public:
    BSTIterator(TreeNode* root) {
        dummy = new Node(0);
        cur = dummy;
        inorder(root);
        cur = dummy;
    }
    
    int next() {
        cur = cur->next;
        return cur->val;
    }
    
    bool hasNext() {
        return (cur->next != nullptr);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

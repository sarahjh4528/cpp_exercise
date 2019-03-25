#include<iostream>
#include<queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}

};

class BSTIterator {
private:
    queue<int> iterQueue;
    void buildIterQueue(TreeNode *node) {
        if (!node)
            return;
        buildIterQueue(node->left);
        iterQueue.push(node->val);
        buildIterQueue(node->right);
    }
public:
    BSTIterator(TreeNode* root) {
        buildIterQueue(root);
    }

    /** @return the next smallest number */
    int next() {
        int ret = iterQueue.front();
        iterQueue.pop();
        return ret;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (!iterQueue.empty());
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
TreeNode *buildTree() {
    TreeNode *root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);
    return root;
}

int main()
{
    TreeNode *root = buildTree();
    BSTIterator* obj = new BSTIterator(root);

    int param_1 = obj->next();
    cout << "Next val is 3, got value: " << param_1 << endl;
    bool param_2 = obj->hasNext();
    cout << "Has next is true, got value: " << param_2 << endl;
    int param_3 = obj->next();
    cout << "Next val is 7, got value: " << param_3 << endl;
    int param_4 = obj->next();
    cout << "Next val is 9, got value: " << param_4 << endl;
    int param_5 = obj->next();
    cout << "Next val is 15, got value: " << param_5 << endl;
    int param_6 = obj->next();
    cout << "Next val is 20, got value: " << param_6 << endl;
    bool param_7 = obj->hasNext();
    cout << "Has next is false, got value: " << param_7 << endl;

    return 0;
}

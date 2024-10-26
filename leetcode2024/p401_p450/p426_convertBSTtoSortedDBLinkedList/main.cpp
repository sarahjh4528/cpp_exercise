/*
Runtime 8 ms Beats 17.16%
Memory 11.76 MB Beats 38.29%
Fastest solution utilizes vector as stack, fill by inOrder travesal
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
    Node* first = NULL;
    Node* prev = NULL;
    void dfs(Node* root) {
        if (!root)
            return;
        dfs(root->left);
        if (prev) {
            prev->right = root;
            root->left = prev;
            prev = root;
        } else {
            first = root;
            prev = first;
        }
        dfs(root->right);
    }
public:
    Node* treeToDoublyList(Node* root) {
        if (!root)
            return NULL;
        dfs(root);
        prev->right = first;
        first->left = prev;
        return first;
    }
};

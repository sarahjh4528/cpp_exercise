#include<iostream>
#include<sstream>
#include<string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
private:
    void serializeHelper(TreeNode *root, ostringstream& oss) {
        if (root) {
            oss << root->val << " ";
            serializeHelper(root->left, oss);
            serializeHelper(root->right, oss);
        } else {
            oss << "# ";
        }
    }

    TreeNode *deserializeHelper(istringstream& iss) {
        string temp;
        iss >> temp;
        if (temp == "#") {
            return NULL;
        }
        TreeNode *root = new TreeNode(stoi(temp));
        root->left = deserializeHelper(iss);
        root->right = deserializeHelper(iss);
        return root;
    }
public:
    TreeNode *buildTree() {
        TreeNode *root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        root->right->left = new TreeNode(4);
        root->right->right = new TreeNode(5);
        return root;
    }
    
    void printTree(TreeNode *root) {
        if (!root)
            return;
        cout << root->val << " ";
        printTree(root->left);
        printTree(root->right);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream oss;
        serializeHelper(root, oss);
        return oss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream iss(data);
        TreeNode *root = deserializeHelper(iss);
        return root;
    }
};

int main()
{
    Solution s;
    TreeNode *root = s.buildTree();
    string serializeTree = s.serialize(root);
    cout << serializeTree << endl;

    TreeNode *deseriaTree = s.deserialize(serializeTree);
    s.printTree(deseriaTree);
    cout << endl;

    return 0;
}

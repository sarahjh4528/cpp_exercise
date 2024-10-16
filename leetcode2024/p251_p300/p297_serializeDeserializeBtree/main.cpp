/*
Runtime 29 ms Beats 56.03%
Memory 47.73 MB Beats 12.45%
TODO: Might be able to make it faster if save to a predefined queue, no need to check index, just pop
*/
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left:
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Codec {
    string dfs(TreeNode *root) {
        if (!root)
            return ",None";
        return ','+to_string(root->val)+dfs(root->left)+dfs(root->right);
    }

    TreeNode* solve(vector<string>& tvals, int& i) {
        if (i >= tvals.size() || tvals[i] == "None") {
            i++;
            return nullptr;
        }
        TreeNode *cur = new TreeNode(stoi(tvals[i]));
        i++;
        cur->left = solve(tvals, i);
        cur->right = solve(tvals, i);
        return cur;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)
            return "";
        return to_string(root->val)+dfs(root->left)+dfs(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.length() == 0)
            return NULL;
        stringstream ss(data);
        string token;
        vector<string> tvals;
        while (getline(ss, token, ','))
            tvals.push_back(token);
        int i = 0;
        return solve(tvals, i);
    }
};

class Solution {
public:
    void printTree(TreeNode *t) {
        if (!t) {
            cout << " null";
            return;
        }
        cout << " " << t->val;
        printTree(t->left);
        printTree(t->right);
    }

    TreeNode* buildTree() {
        TreeNode *top = new TreeNode(1);
        top->left = new TreeNode(2);
        top->right = new TreeNode(3);
        top->right->left = new TreeNode(4);
        top->right->right = new TreeNode(5);
        return top;
    }

};

int main()
{
    // Your Codec object will be instantiated and called as such:
    // Codec ser, deser;
    // TreeNode* ans = deser.deserialize(ser.serialize(root));
    Solution s;

    TreeNode *root = s.buildTree();
    s.printTree(root);
    Codec ser, deser;
    TreeNode* ans = deser.deserialize(ser.serialize(root));
    s.printTree(ans);

    return 0;
}

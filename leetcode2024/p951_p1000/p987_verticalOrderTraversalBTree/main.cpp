#include<bits/stdc++.h>
#include<iostream>
#include<map>
#include<queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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

#if 0
    TreeNode* buildTree() {
        TreeNode *top = new TreeNode(3);
        top->left = new TreeNode(9);
        top->right = new TreeNode(20);
        top->right->left = new TreeNode(15);
        top->right->right = new TreeNode(7);
        return top;
    }
#else
    TreeNode* buildTree() {
        TreeNode *top = new TreeNode(1);
        top->left = new TreeNode(2);
        top->right = new TreeNode(3);
        top->left->left = new TreeNode(4);
        top->left->right = new TreeNode(6);
        top->right->left = new TreeNode(5);
        top->right->right = new TreeNode(7);
        return top;
    }
    
#endif

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int,int>>> pmap;      // col : [row][col]
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));             // <TreeNode*, col>
        while (!q.empty()) {
            int qsize = q.size();
            for (int i = 0; i < qsize; i++) {
                auto [cur, ni] = q.front();
                q.pop();
                pmap[ni].push_back(make_pair(ni,cur->val));
                if (cur->left)
                    q.push(make_pair(cur->left, ni-1));
                if (cur->right)
                    q.push(make_pair(cur->right, ni+1));
            }
        }
        vector<vector<int>> res;
        for (auto it = pmap.begin(); it != pmap.end(); it++) {
            auto& v = it->second;
            sort(v.begin(), v.end(), [&](auto p1, auto p2) {
                if (p1.first == p2.first)
                    return p1.second < p2.second;
                return p1.first < p2.first;
            });
            vector<int> tmp;
            for (auto p : v)
                tmp.push_back(p.second);
            res.push_back(tmp);
        }
        return res;
    }

};

int main()
{
    Solution s;

    TreeNode *root = s.buildTree();
    s.printTree(root);
    cout << endl;

    vector<vector<int>> output = s.verticalTraversal(root);
    for (auto row : output) {
        for (auto v : row)
            cout << v << " ";
        cout << ", ";
    }
    cout << endl;

    return 0;
}

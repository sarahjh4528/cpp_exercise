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

/*
Runtime 0 ms Beats 100.00%
Memory 13.60 MB Beats 99.40%

Time Complexity: O(Nlog(N/k)))), where k is the width of the tree,
i.e. k is also the number of columns in the result.

1st step, O(N)

2nd step, sort the hashmap entry by entry. Sorting k equal-sized subgroups
of with total N elements would be O(k⋅N/k(logN/k))
3rd step. O(N) to extract the results from the hashmap.
*/
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int, int>>> tmap;  // col : [row, val]
        queue<pair<TreeNode*, int>> q;          // [TreeNode*, col]
        q.push(make_pair(root, 0));
        int row = 0;
        while (!q.empty()) {
            int qsize = q.size();
            for (int i = 0; i < qsize; i++) {
                auto [cur, ni] = q.front();
                q.pop();
                tmap[ni].push_back(make_pair(row, cur->val));
                if (cur->left)
                    q.push(make_pair(cur->left, ni-1));
                if (cur->right)
                    q.push(make_pair(cur->right, ni+1));
            }
            row++;
        }
        vector<vector<int>> res;
        for (auto it = tmap.begin(); it != tmap.end(); it++) {
            auto& v = it->second;
            sort(v.begin(), v.end(), [&](auto n1, auto n2) {
                if (n1.first == n2.first)
                    return n1.second < n2.second;
                return n1.first < n2.first;
            });
            vector<int> curV;
            for (auto n : v)
                curV.push_back(n.second);
            res.push_back(curV);
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

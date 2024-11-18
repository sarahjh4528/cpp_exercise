/*
Constraints:

0 <= s.length <= 3 * 10^4
s consists of digits, '(', ')', and '-' only.
*/
#include<bits/stdc++.h>
#include<iostream>

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
    TreeNode* dfs(string& s, int& i) {
        bool negative = false;
        TreeNode* cur = NULL;
        while (i < s.length()) {
            if (s[i] == '-') {
                negative = true;
                i++;
            } else if (s[i] == '(') {
                i++;
                TreeNode *node = dfs(s, i);
                if (!cur->left)
                    cur->left = node;
                else if (!cur->right)
                    cur->right = node;
            } else if (s[i] == ')') {
                i++;
                return cur;
            } else {
                int num = 0;
                while (i < s.length() && isdigit(s[i])) {
                    num = num*10 + (s[i]-'0');
                    i++;
                }
                num = (negative)? -num : num;
                cur = new TreeNode(num);
            }
        }
        return cur;
    }
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

/*
Design: Recursive solution
Runtime 6 ms Beats 63.41%
Memory 25.39 MB Beats 96.88%
*/
    TreeNode* str2tree(string s) {
        if (s.length() == 0)
            return NULL;
        int i = 0;
        return dfs(s, i);
    }

};

int main()
{
    vector<string> vs = {
        "4(2(3)(1))(6(5))",
        "4(2(3)(1))(6(5)(7))",
        "-4(2(3)(1))(6(5)(7))"
    };
    Solution s;

    for (auto str : vs) {
        cout << str << endl;
        TreeNode* root = s.str2tree(str);
        s.printTree(root);
        cout << endl;
    }

    return 0;
}

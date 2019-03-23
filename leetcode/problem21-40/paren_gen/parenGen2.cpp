#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    void genParenHelper(int n, int left, int right, string genStr, vector<string>& ret) {
        if (left == n && right == n) {
            ret.push_back(genStr);
        } else if (left > n || right > n || left > right) {
            return;
        } else {
            genParenHelper(n, left + 1, right, genStr+")", ret);
            genParenHelper(n, left, right+1, genStr+"(", ret);
        }
    }

    vector<string> generateParenthesis(int n) {
        if (n < 1)
            return vector<string>{};
        vector<string> ret;
        genParenHelper(n, 0, 0, "", ret);
        return ret;
    }
};
int main()
{
    Solution s;
    vector<string> genParens = s.generateParenthesis(3);
    for (auto p : genParens)
        cout << p << " " << endl;

    return 0;
}

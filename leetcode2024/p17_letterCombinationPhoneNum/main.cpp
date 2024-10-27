/*
Runtime 0 ms Beats 100.00%
Memory 7.90 MB Beats 98.59%
*/
class Solution {
    unordered_map<char, string> map = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
public:
    void dfs(string const& digits, int i, string& path, vector<string>& res) {
        if (i == digits.size()) {
            res.push_back(path);
            return;
        }
        for (auto c : map[digits[i]]) {
            path.push_back(c);
            dfs(digits, i+1, path, res);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0)
            return {};
        vector<string> res;
        string path = "";
        dfs(digits, 0, path, res);
        return res;
    }
};

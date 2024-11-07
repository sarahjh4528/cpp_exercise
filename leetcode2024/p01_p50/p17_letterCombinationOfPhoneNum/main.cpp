/*
Runtime 0 ms Beats 100.00%
Memory 8.78 MB Beats 20.37%

Time: O(4^N * N), Space: O(n)
4 : longest string length in map
*/
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

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

class Solution {
    void solve(string& digits, int i, string& cur, vector<string>& res) {
        if (i == digits.length()) {
            res.push_back(cur);
            return;
        }
        for (auto c : map[digits[i]]) {
            cur += c;
            solve(digits, i+1, cur, res);
            cur.pop_back();
        }
    }

public:
    void printVec(vector<string>& v) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0)
            return {};

        vector<string> res;
        string cur;
        solve(digits, 0, cur, res);
        return res;
    }
};

int main()
{

    vector<string> vdigits = { "23", "", "2" };
    Solution s;

    for (auto digits : vdigits) {
        cout << digits << endl;
        vector<string> output = s.letterCombinations(digits);
        cout << "Letter combinations: " << endl;
        s.printVec(output);
    }
    return 0;
}

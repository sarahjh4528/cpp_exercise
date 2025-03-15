#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
    unordered_map<char, string> cmap = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    void getCombinations(string const& digits, int i, string& curstr, vector<string>& res) {
        if (i == digits.length()) {
            res.push_back(curstr);
            return;
        }
        for (auto c : cmap[digits[i]]) {
            curstr += c;
            getCombinations(digits, i+1, curstr, res);
            curstr.pop_back();
        }
    }
public:
    void printVec(vector<string>& v) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

/*
0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
*/
/*
Runtime 0 ms Beats 100.00%
Memory 9.16 MB Beats 73.62%
*/
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.length() == 0)
            return res;
        string curstr;
        getCombinations(digits, 0, curstr, res);
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

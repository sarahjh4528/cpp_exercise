#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

unordered_map<char, vector<string>> keyDict = {
    {'2', {"a", "b", "c"}},
    {'3', {"d", "e", "f"}},
    {'4', {"g", "h", "i"}},
    {'5', {"j", "k", "l"}},
    {'6', {"m", "n", "o"}},
    {'7', {"p", "r", "q", "s"}},
    {'8', {"t", "u", "v"}},
    {'9', {"w", "x", "y", "z"}}
};

class Solution {
public:
    void printVec(vector<string> &strV) {
        for (auto s: strV) {
            cout << s << endl;
        }
    }
    vector<string> combinationHelper(string& digits, int index) {
        if (index == digits.length() - 1)
            return keyDict[digits[index]];
        vector<string> options = keyDict[digits[index]];
        vector<string> combinations = combinationHelper(digits, index + 1);
        vector<string> ret;
        for (auto s : options) {
            for (auto c : combinations) {
                ret.push_back(s+c);
            }
        }
        return ret;
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};
        return combinationHelper(digits, 0);
    }
};

int main()
{
    string input = "23";
//    string input = "";
    Solution s;
    vector<string> output = s.letterCombinations(input);
    s.printVec(output);
    return 0;
}

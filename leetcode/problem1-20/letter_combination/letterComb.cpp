#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::unordered_map;

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
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};

        vector<string> strComb;
        if (digits.size() == 1) {
            return keyDict[digits[0]];
        }

        vector<string> keyLetters = keyDict[digits[0]];
        vector<string> retVec = letterCombinations(digits.substr(1, (digits.size() - 1)));
        for (auto l : keyLetters) {
            for (auto r : retVec) {
                strComb.push_back(l + r);
            }
        }
        return strComb;
    }
};

int main()
{
//    string input = "23";
    string input = "";
    Solution s;
    vector<string> output = s.letterCombinations(input);
    s.printVec(output);
    return 0;
}

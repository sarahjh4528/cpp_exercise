#include<iostream>
#include<map>
#include<vector>
#include<string>

using std::endl;
using std::cout;
using std::map;
using std::vector;
using std::string;

class Solution {
public:
    int romanToInt(string s) {
        int ret = 0;
        map<int, string> dict = {
            {1, "I"},
            {4, "IV"},
            {5, "V"},
            {9, "IX"},
            {10, "X"},
            {40, "XL"},
            {50, "L"},
            {90, "XC"},
            {100, "C"},
            {400, "CD"},
            {500, "D"},
            {900, "CM"},
            {1000, "M"}
        };

        int index = 0, strLen = s.length();
        while (index < strLen) {
            for (auto it = dict.crbegin(); it != dict.crend(); ++it) {
                string rStr = it->second;
                while (rStr == s.substr(index, rStr.length())) {
                    ret += it->first;
                    index += rStr.length();
                }
            }
        }
        return ret;
    }
};

int main()
{
    vector<string> input = {
        "III",
        "IV",
        "LVIII",
        "MCMXCIV",
        "IX",
        "MMMCMXCIX"
    };

    Solution s;
    for (auto str : input) {
        cout << "Input: " << str << endl;
        int out = s.romanToInt(str);
        cout << "Output: " << out << endl;
    }
    return 0;
}

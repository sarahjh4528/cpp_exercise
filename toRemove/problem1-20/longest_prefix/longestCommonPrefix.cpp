#include<iostream>
#include<vector>
#include<string>

using std::cout;
using std::endl;
using std::string;
using std::vector;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";

        bool match = true;
        int i;
        for (i = 0; i != strs[0].length(); ++i) {
            char c = strs[0][i];
            for (auto str : strs) {
                if (str.length() <= i || str[i] != c) {
                    match = false;
                    break;
                }
            }
            if (!match)
                break;
        }
        if (i > 0)
            return strs[0].substr(0, i);
        else
            return "";
    }
};

int main()
{
//    vector<string> input = {"flower", "flow", "flight"};
//    vector<string> input = {"dog", "racecar", "car"};
    vector<string> input = {};

    Solution s;
    string output = s.longestCommonPrefix(input);
    cout << "Longest Command Prefix: " << output << endl;
    return 0;
}

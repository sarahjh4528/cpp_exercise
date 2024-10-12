#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubString(string s) {
        int longest = 0, curLen = 0, rStart = 0;
        int pos[256] = {0};

        for (int i = 0; i < s.length(); ++i) {
            if (pos[s[i]]) {
                // found a dup char
                longest = max(longest, curLen);
                rStart = (rStart > pos[s[i]])? rStart : pos[s[i]];
                curLen = i - rStart + 1;
            } else {
                ++curLen;
            }
            pos[s[i]] = i + 1;    // Save index one bigger than real index to avoid index 0
        }
        return (longest > curLen)? longest : curLen;
    }
};
int main()
{
    vector<string> strV = {
        "abcabcbb",    // 3
        "abcaefbb",    // 5
        "abcaebib",    // 5
        "abcaebbib",   // 4
        "bbbbbb",      // 1
        "abba",        // 2
        "ckilbkd",     // 5
    };

    Solution s;

    for (auto str : strV) {
        cout << str << endl;
        int len = s.lengthOfLongestSubString(str);
        cout << "Longest non dup substring len: " << len << endl;
    }
    return 0;
}

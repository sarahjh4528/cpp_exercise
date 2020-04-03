#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    // 24ms, faster than 51%, 11MB, less than 49%.
    // To improve, instead of using unordered_map, use char array to save char frequency.
    int lengthOfLongestSubstring(string s) {
        int strLen = s.size();
        if (strLen <= 1)
            return strLen;

        unordered_map<char, int> map;
        int longestLen = 0, left = -1;
        for (int i = 0; i < strLen; i++) {
            if (map.find(s[i]) != map.end() && map[s[i]] >= left)
                left = map[s[i]];
            longestLen = max(longestLen, i - left);
            map[s[i]] = i;
        }
        return longestLen;
    }
};

int main()
{
    vector<string> inputs = {
        "abcabcbb",
        "bbbbb",
        "pwwkew",
        " ",
        "",
        "abc",
        "tmmzuxt",
    };

    Solution s;
    for (auto str : inputs) {
        cout << str << endl;
        int len = s.lengthOfLongestSubstring(str);
        cout << "Longest substring length: " << len << endl;
    }

    return 0;
}

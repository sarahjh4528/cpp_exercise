#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    void printVec(vector<string>& v) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

/*
Runtime 7 ms Beats 73.25%
Memory 12.00 MB Beats 58.66%

Time: O(n)
Space: O(n)
*/
    int lengthOfLongestSubstring(string s) {
        int res = 0, start = 0;
        unordered_map<char, int> cmap;
        for (int i = 0; i < s.length(); i++) {
            if (cmap.count(s[i]))
                start = max(start, cmap[s[i]] + 1);
            cmap[s[i]] = i;
            res = max(res, i - start + 1);
        }
        return res;
    }
};

int main()
{
    vector<string> vstrs = {"abcabcbb","bbbbb","pwwkew", "tmmzuxt"};
    Solution s;

    for (auto str : vstrs) {
        cout << str << endl;
        int output = s.lengthOfLongestSubstring(str);
        cout << "Longest substring without repeating char: " << output << endl;
    }

    return 0;
}


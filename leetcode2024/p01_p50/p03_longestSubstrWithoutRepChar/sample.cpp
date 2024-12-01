/*
Constraints:

0 <= s.length <= 5 * 10^4
s consists of English letters, digits, symbols and spaces.
*/
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

    int lengthOfLongestSubstring(string s) {
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


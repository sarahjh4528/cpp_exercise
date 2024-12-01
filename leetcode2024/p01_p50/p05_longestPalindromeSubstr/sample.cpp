/*
Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.
*/
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
    }
};

int main() {
    Solution s;
    vector<string> vs = { "babad", "cbbd" };

    for (auto str : vs) {
        cout << "Input : " << endl;
        cout << str << endl;
        string output = s.longestPalindrome(str);
        cout << "Longest palindrome: " << output << endl;
    }

    return 0;
}

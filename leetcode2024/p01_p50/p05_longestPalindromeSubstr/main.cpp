/*
Runtime 0 ms Beats 100.00%
Memory 8.18 MB Beats 99.64%
*/
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int slen = s.length();
        if (slen == 1)
            return s;

        int i = 0, start = 0, llen = 0;
        while (i < slen) {
            if (slen - i < (llen / 2))
                break;
            int left = i, right = i;
            while (right < slen && s[right] == s[right+1])  // Skip same chars, guarantee palindrome
                right++;

            i = right + 1;                                  // Do not process same char in further steps
            while (left > 0 && right < slen - 1 && s[left-1] == s[right+1]) {
                left--;
                right++;
            }
            if (right - left + 1 > llen) {
                start = left;
                llen = right - left + 1;
            }
        }
        return s.substr(start, llen);
        
    }
};

int main() {
    Solution s;
    vector<string> vs = { "babad", "cbbd", "abacab" };

    for (auto str : vs) {
        cout << "Input : " << endl;
        cout << str << endl;
        string output = s.longestPalindrome(str);
        cout << "Longest palindrome: " << output << endl;
    }

    return 0;
}

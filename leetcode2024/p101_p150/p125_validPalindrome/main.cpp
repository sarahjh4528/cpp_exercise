/*
Runtime 0 ms Beats 100.00%
Memory 8.69 MB Beats 98.80%
*/

#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
    bool validchar(char c) {
        return (isdigit(c) || isalpha(c));
    }
public:
    bool isPalindrome(string s) {
        int slen = s.length();
        if (slen == 1)
            return true;
        int left = 0, right = slen-1;
        while (left < right) {
            if (!validchar(s[left])) {
                left++;
                continue;
            }
            if (!validchar(s[right])) {
                right--;
                continue;
            }
            if (tolower(s[left]) != tolower(s[right]))
                return false;

            left++;
            right--;
        }
        return true;
    }
};

int main()
{
    vector<string> input = {
        "A man, a plan, a canal: Panama",
        "race a car",
        " ",
        ".,"
    };
    Solution s;

    for (auto str : input) {
        cout << str << endl;
        bool output = s.isPalindrome(str);
        cout << "Is palindrome: " << output << endl;
    }
    return 0;
}

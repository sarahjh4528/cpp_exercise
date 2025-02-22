/*
Runtime 0 ms Beats 100.00%
Memory 8.69 MB Beats 98.80%
*/

#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.length()-1;
        while (l < r) {
            if (!isalnum(s[l]))
                l++;
            else if (!isalnum(s[r]))
                r--;
            else {
                if (tolower(s[l++]) != tolower(s[r--]))
                    return false;
            }
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

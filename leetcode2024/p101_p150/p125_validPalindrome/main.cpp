/*
Runtime 2 ms Beats 89.86%
Memory 9.66 MB Beats 11.81%
Same design as fastest solution
*/
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string str1 = "", str2 = "";
        for (auto c : s) {
            if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z')) {
                str1 += tolower(c);
            }
        }
        str2 = str1;
        reverse(str2.begin(), str2.end());
        return (str1 == str2);
    }
};

int main()
{
    vector<string> input = {
        "A man, a plan, a canal: Panama",
        "race a car",
        " "
    };
    Solution s;

    for (auto str : input) {
        cout << str << endl;
        bool output = s.isPalindrome(str);
        cout << "Is palindrome: " << output << endl;
    }
    return 0;
}

/*
Constraints:

1 <= s.length <= 2 * 10^5
s consists only of printable ASCII characters.
*/
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
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

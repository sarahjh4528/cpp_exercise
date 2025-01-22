#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    void printVec(vector<int>& v) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }
/*
1 <= s.length <= 10^5
s consists of lowercase English letters and stars *.
The operation above can be performed on s.
*/
/*
Runtime 11 ms Beats 87.25%
Memory 26.81 MB Beats 89.93%

Design: Use 2 pointers to simulate stack. Use stack will timeout.

Time: O(n), n: input string length
Space: O(1)

*/
    string removeStars(string s) {
        int i = 0;
        for (int j = 0; j < s.length(); j++) {
            if (s[j] == '*') {
                if (i > 0)
                    i--;
            } else {
                s[i++] = s[j];
            }
        }
        return s.substr(0, i);
    }
};

int main()
{
    vector<string> vs = {
        "leet**cod*e",
        "erase*****"
    };
    Solution s;

    for (auto str : vs) {
        cout << "Before rm *: " << str << endl;
        string output = s.removeStars(str);
        cout << "After rm *: " << output << endl;
    }

    return 0;
}

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
0 <= s.length <= 200
s consists of English letters (lower-case and upper-case), digits (0-9), ' ', '+', '-', and '.'.
*/
    int myAtoi(string s) {
    }
};

int main()
{
    vector<string> vs = {
        "42",
        " -042",
        "1337c0d3",
        "0-1",
        "words and 987"
    };
    Solution s;

    for (auto str : vs) {
        int output = s.myAtoi(str);
        cout << "myStoi(" << str << ") = " << output << endl;
    }

    return 0;
}

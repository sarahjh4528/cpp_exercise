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
Fastest solution utilizes variables instead of unordered_map
*/
    bool isNumber(string s) {
    }

};

int main()
{
    vector<string> vs = {
        "0", "e", ".", "2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10",
        "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789",
        "abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"         // invalid
    };
    Solution s;

    for (auto str : vs) {
        cout << "Input string: " << str << endl;
        bool output = s.isNumber(str);
        cout << "Is number: " << output << endl;
    }

    return 0;
}

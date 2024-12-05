/*
Constraints:

1 <= s.length <= 20
s consists of digits only.
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

    vector<string> restoreIpAddresses(string s) {
    }
};

int main()
{
    vector<string> vs = {
        "25525511135",
        "0000",
        "101023"
    };
    Solution s;

    for (auto str : vs) {
        vector<string> output = s.restoreIpAddresses(str);
        s.printVec(output);
    }
    return 0;
}

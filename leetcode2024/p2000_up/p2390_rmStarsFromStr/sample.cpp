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
    string removeStars(string s) {
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

#include<bits/stdc++.h>
#include<iostream>
#include<queue>

using namespace std;

class Solution {
public:
    void printVec(vector<int>& v) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

    string reorganizeString(string s) {
    }
};

int main()
{
    vector<string> vs = {
        "aab",
        "aaab"
    };
    Solution s;

    for (auto str : vs) {
        cout << str << endl;
        string output = s.reorganizeString(str);
        cout << "After reorg: " << output << endl;
    }
    return 0;
}

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

    string minWindow(string s, string t) {
    }
};

int main()
{
    vector<string> vs = {
        "ADOBECODEBANC",
        "a",
        "a"
    };
    vector<string> vt = {
        "ABC",
        "a",
        "aa"
    };
    Solution s;
    for (int i = 0; i < vs.size(); i++) {
        cout << "s; " << vs[i] << ", t: " << vt[i] << endl; 
        string output = s.minWindow(vs[i], vt[i]);
        cout << "Min window substring includes (" << vt[i] << ") : " << endl;
        cout << output << endl;
    }

    return 0;
}

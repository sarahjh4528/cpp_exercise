#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    void printVec(vector<string>& v) {
        cout << "( ";
        for (auto i : v)
            cout << i << " ";
        cout << " ) ";
    }

    vector<vector<string>> groupStrings(vector<string>& strings) {
    }
};

int main()
{
    vector<vector<string>> vstrings = {
        {"abc","bcd","acef","xyz","az","ba","a","z"},
        {"a"}
    };
    Solution s;

    for (int i = 0; i < vstrings.size(); i++) {
        cout << "Input: " << endl;
        s.printVec(vstrings[i]);
        cout << endl;
        vector<vector<string>> output = s.groupStrings(vstrings[i]);
        cout << "Output : " << endl;
        for (auto v : output)
            s.printVec(v);
        cout << endl;
    }
    return 0;
}

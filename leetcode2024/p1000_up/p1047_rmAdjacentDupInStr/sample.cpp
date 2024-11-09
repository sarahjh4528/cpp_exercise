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

    string removeDuplicates(string s) {
    }
};

int main()
{
    vector<string> vs = {
        "abbaca", "azxxzy"
    };
    Solution s;

    for (auto str : vs) {
        cout << "Input : " << str << endl;
        string output = s.removeDuplicates(str);
        cout << "Output : " << output << endl;
    }
    return 0;
}

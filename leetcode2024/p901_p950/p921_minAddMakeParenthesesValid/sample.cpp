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


    int minAddToMakeValid(string s) {
    }
};

int main()
{
    vector<string> input = { "())", "(((" };
    Solution s;

    for (auto str : input) {
        cout << str << endl;
        int output = s.minAddToMakeValid(str);
        cout << "Min number of move to make it valid : " << output << endl;
    }
    return 0;
}

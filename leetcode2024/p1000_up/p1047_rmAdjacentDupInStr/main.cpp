/*
Runtime 0 ms Beats 100.00%
Memory 12.01 MB Beats 86.09%
*/
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
        int stackPtr = -1;
        int i = 0;
        while (i < s.length()) {
            if (stackPtr >= 0 && s[i] == s[stackPtr]) {
                stackPtr--;
            } else {
                stackPtr++;
                s[stackPtr] = s[i];
            }
            i++;
        }
        return s.substr(0, stackPtr+1);
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

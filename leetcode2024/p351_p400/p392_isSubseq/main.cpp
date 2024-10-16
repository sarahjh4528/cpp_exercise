/*
Runtime 3 ms Beats 45.41%
Memory 7.83 MB Beats 17.54%
Fastest solution similar design, iterate through iterator
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

    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        while (i < s.length() && j < t.length()) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }
        return i == s.length();
    }
};

int main()
{
    vector<string> vs = {"abc", "axc"};
    vector<string> vt = {"ahbgdc", "ahbgdc"};
    Solution s;

    vector<int> input = {1,2,3,4,5,6};
    s.printVec(input);
    return 0;
}

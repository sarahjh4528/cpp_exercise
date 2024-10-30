/*
Runtime 0 ms Beats 100.00%
Memory 11.14 MB Beats 74.98%
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

    string longestCommonPrefix(vector<string>& strs) {
        int vlen = strs.size();
        if (vlen == 1)
            return strs[0];

        int j = 0;
        for (auto c : strs[0]) {
            for (int i = 1; i < strs.size(); i++) {
                if (j == strs[i].length() || strs[i][j] != c)
                    return strs[0].substr(0, j);
            }
            j++;
        }
        return strs[0].substr(0, j);
    }
};

int main()
{
    vector<string> strs = {"flower","flow","flight"};
    Solution s;

    s.printVec(strs);
    string output = s.longestCommonPrefix(strs);
    cout << "Common prefix: " << output << endl;
        
    return 0;
}

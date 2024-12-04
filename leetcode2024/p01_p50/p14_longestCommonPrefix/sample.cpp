/*
Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.
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

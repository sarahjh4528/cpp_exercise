/*
Constraints:

1 <= strs.length <= 10^4
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.
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

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    }
};

int main()
{
    vector<vector<string>> vstrs = {
        {"eat","tea","tan","ate","nat","bat"},
        {""},
        {"a"},
    };
    Solution s;

    for (auto strs : vstrs) {
        vector<vector<string>> output = s.groupAnagrams(strs);
        for (auto v : output)
            s.printVec(v);
    }
    return 0;
}

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

/*
0 <= s.length <= 100
0 <= t.length <= 10^4
s and t consist only of lowercase English letters.
*/
/*
Runtime 0 ms Beats 100.00%
Memory 8.42 MB Beats 75.59%

Time: O(n), n: len of t
Space: O(1)
*/
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        int slen = s.length(), tlen = t.length();
        while (i < slen && j < tlen) {
            if (s[i] == t[j])
                i++;
            j++;
        }
        return i == slen;
    }
};

int main()
{
    vector<string> vs = {"abc", "axc"};
    vector<string> vt = {"ahbgdc", "ahbgdc"};
    Solution s;


    for (int i = 0; i < vs.size(); i++) {
        cout << "s : " << vs[i] << endl;
        cout << "t : " << vt[i] << endl;
        bool output = s.isSubsequence(vs[i], vt[i]);
        cout << "s is subseq: " << output << endl;
    }
    return 0;
}

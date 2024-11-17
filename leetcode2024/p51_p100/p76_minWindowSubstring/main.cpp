/*
Runtime 23 ms Beats 38.53%
Memory 11.30 MB Beats 12.99%

Fastest solution has same design, use char array instead of unordered_map
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

    string minWindow(string s, string t) {
        if (s.length() == 0 || t.length() == 0 || s.length() < t.length())
            return "";
        unordered_map<char, int> smap;
        unordered_map<char, int> tmap;
        for (auto c : t)
            tmap[c]++;
        int need = tmap.size(), have = 0;
        int left = 0, right = 0;
        int resLen = INT_MAX, resStart = 0;
        while (right < s.length()) {
            char c = s[right];
            smap[c]++;
            if (tmap.count(c) && tmap[c] == smap[c])
                have++;
            while (left <= right && have == need) {
                char lc = s[left];
                if (resLen > right-left+1) {
                    resLen = right - left + 1;
                    resStart = left;
                }
                if (tmap.count(lc) && tmap[lc] == smap[lc])
                    have--;
                smap[lc]--;
                left++;
            }
            right++;
        }
        return (resLen == INT_MAX)? "" : s.substr(resStart, resLen);
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

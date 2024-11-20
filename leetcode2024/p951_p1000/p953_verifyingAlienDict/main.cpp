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

    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> omap;
        for (int i = 0; i < order.length(); i++)
            omap[order[i]] = i;

        for (int i = 1; i < words.size(); i++) {
            int j = 0;
            string& w1 = words[i-1], w2 = words[i];
            while (j < w1.length() && j < w2.length()) {
                if (omap[w2[j]] - omap[w1[j]] < 0)
                    return false;
                else if (omap[w2[j]] - omap[w1[j]] > 0)
                    return true;
                j++;
            }
            if (w1.length() > w2.length())
                return false;
        }
        return true;
    }
};

int main()
{
    vector<vector<string>> vwords = {
        {"hello","leetcode"},
        {"word","world","row"},
        {"apple","app"},
        {"fxasxpc","dfbdrifhp","nwzgs","cmwqriv","ebulyfyve","miracx","sxckdwzv","dtijzluhts","wwbmnge","qmjwymmyox"}
    };
    vector<string> vorder = {
        "hlabcdefgijkmnopqrstuvwxyz",
        "worldabcefghijkmnpqstuvxyz",
        "abcdefghijklmnopqrstuvwxyz",
        "zkgwaverfimqxbnctdplsjyohu"
    };
    Solution s;

    for (int i = 0; i < vorder.size(); i++) {
        s.printVec(vwords[i]);
        cout << "Order: " << vorder[i] << endl;
        bool output = s.isAlienSorted(vwords[i], vorder[i]);
        cout << "Is ordered: " << output << endl;
    }

    return 0;
}

/*
Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 20
order.length == 26
All characters in words[i] and order are English lowercase letters.
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

    bool isAlienSorted(vector<string>& words, string order) {
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

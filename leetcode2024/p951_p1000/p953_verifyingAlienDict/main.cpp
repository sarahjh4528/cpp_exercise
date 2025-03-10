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

/*
Runtime 1 ms Beats 28.69%
Memory 12.74 MB Beats 37.25%

Same design as fastest solution

Time complexity:
O(n) for setting omap, where n = 26, therefore constant, O(1)
O(m*wordlenth) for comparing, where m = words.size(), wordlen <= 100.

*/
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> omap;
        for (int i = 0; i < order.length(); i++)
            omap[order[i]] = i;
        for (int i = 1; i < words.size(); i++) {
            string& w1 = words[i-1], w2 = words[i];
            int j = 0;
            bool inOrder = false;
            while (j < w1.length() && j < w2.length()) {
                if (omap[w2[j]] > omap[w1[j]]) {
                    inOrder = true;
                    break;
                } else if (omap[w2[j]] < omap[w1[j]])
                    return false;
                j++;
            }
            if (!inOrder && w1.length() > w2.length())
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

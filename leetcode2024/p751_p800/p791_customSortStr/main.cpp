/*
Runtime 1 ms Beats 50.91%
Memory 8.54 MB Beats 31.52%

Fastest solution utilize sort function with a custom comparator

Sample code:
string customSortString(string order, string s) {
        vector<int> charToOrder(26, 100);
        for (int i = 0; i < size(order); ++i) {
            charToOrder[order[i] - 'a'] = i;
        }

        sort(begin(s), end(s),[&charToOrder](auto&& lhs, auto&& rhs) {
            return charToOrder[lhs - 'a'] < charToOrder[rhs - 'a']; 
        });
        return s;
    }
*/
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> cnt;
        for (int c : s)
            cnt[c]++;

        string res;
        for (auto c : order) {
            if (cnt.count(c)) {
                for (int i = 0; i < cnt[c]; i++)
                    res += c;
                cnt[c] = 0;
            }
        }
        for (auto it = cnt.begin(); it != cnt.end(); it++) {
            if (it->second > 0) {
                for (int i = 0; i < it->second; i++)
                    res += it->first;
            }
        }
        return res;
    }

};

int main()
{
    vector<string> norders = {"cba", "bcafg"};
    vector<string> ns = {"abcd", "abcd"};
    Solution s;

    for (int i = 0; i < ns.size(); i++) {
        cout << "order : " << norders[i] << endl;
        cout << "s : " << ns[i] << endl;
        string output = s.customSortString(norders[i], ns[i]);
        cout << "Output: " << output << endl;
    }

    return 0;
}

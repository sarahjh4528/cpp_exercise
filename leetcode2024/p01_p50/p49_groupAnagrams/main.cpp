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
#if 0
/*
Runtime 31 ms Beats 22.15%
Memory 29.97 MB Beats 15.68%
*/
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> smap;
        for (auto str : strs) {
            vector<int> cnt(26, 0);
            for (auto c : str)
                cnt[c-'a']++;
            string cur = "";
            for (int i = 0; i < 26; i++) {
                if (cnt[i] > 0) {
                    char tmp = i + 'a';
                    cur += tmp+to_string(cnt[i]);
                }
            }
            smap[cur].push_back(str);
        }
        vector<vector<string>> res;
        for (auto it = smap.begin(); it != smap.end(); it++) {
            res.push_back(it->second);
        }
        return res;
    }
#else
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for (auto str : strs) {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            if (map.count(tmp))
                map[tmp].push_back(str);
            else
                map[tmp] = {str};
        }
        vector<vector<string>> res;
        for (auto it = map.begin(); it != map.end(); it++)
            res.push_back(it->second);
        return res;
    }
#endif
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

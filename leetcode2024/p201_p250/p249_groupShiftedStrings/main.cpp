/*
Runtime 0 ms Beats 100.00%
Memory 10.58 MB Beats 73.99%
*/
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
    string getKey(string& str) {
        int start = str[0];
        string key = "";
        for (auto c : str) {
            key += ((c-start + 26)%26 + 'a');
        }
        return key;
    }
public:
    void printVec(vector<string>& v) {
        cout << "( ";
        for (auto i : v)
            cout << i << " ";
        cout << " ) ";
    }

    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> smap;
        for (auto str : strings) {
            string hashKey = getKey(str);
            smap[hashKey].push_back(str);
        }
        vector<vector<string>> res;
        for (auto it = smap.begin(); it != smap.end(); it++)
            res.push_back(it->second);
        return res;
    }
};

int main()
{
    vector<vector<string>> vstrings = {
        {"abc","bcd","acef","xyz","az","ba","a","z"},
        {"a"}
    };
    Solution s;

    for (int i = 0; i < vstrings.size(); i++) {
        cout << "Input: " << endl;
        s.printVec(vstrings[i]);
        cout << endl;
        vector<vector<string>> output = s.groupStrings(vstrings[i]);
        cout << "Output : " << endl;
        for (auto v : output)
            s.printVec(v);
        cout << endl;
    }
    return 0;
}

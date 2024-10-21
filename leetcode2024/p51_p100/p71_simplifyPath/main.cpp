/*
Runtime 4 ms Beats 70.14%
Memory 14.55 MB Beats 5.02%
*/
#include<bits/stdc++.h>
#include<iostream>
#include<sstream>

using namespace std;

class Solution {
public:
    void printVec(vector<int>& v) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

    string simplifyPath(string path) {
        stringstream ss(path);
        string token;
        vector<string> st;
        while (getline(ss, token, '/')) {
            if (token == "..") {
                if (!st.empty())
                    st.pop_back();
                continue;
            }
            if (token == "" || token == ".")
                continue;
            st.push_back(token);
        }
        string res = "";
        for (auto str : st)
            res = res + '/' + str;
        res = (res.empty())? "/" : res;
        return res;
    }
};

int main()
{
    vector<string> vstr = {
        "/home/", "/home//foo/", "/home/user/Documents/../Pictures", "/../", "/.../a/../b/c/../d/./"
    };
    Solution s;

    for (auto str : vstr) {
        cout << str << endl;
        string output = s.simplifyPath(str);
        cout << "Output: " << endl;
        cout << output << endl;
    }
    return 0;
}

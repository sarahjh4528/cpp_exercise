#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    void printVec(vector<char>& v) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

/*
Runtime 0 ms Beats 100.00%
Memory 13.88 MB Beats 80.88%
*/
    int compress(vector<char>& chars) {
        int res = 0, curCnt = 1, n = chars.size();
        if (n == 1)
            return n;
        char cur = chars[0];
        int i = 0;
        while (i < n) {
            while (i+curCnt < n && chars[i] == chars[i+curCnt])
                curCnt++;
            chars[res++] = chars[i];
            if (curCnt > 1) {
                for (auto i : to_string(curCnt))
                    chars[res++] = i;
            }
            i += curCnt;
            curCnt = 1;
        }
        return res;
    }
};

int main()
{
    vector<vector<char>> vchars = {
        {'a','a','b','b','c','c','c'},
        {'a'},
        {'a','b','b','b','b','b','b','b','b','b','b','b','b'},
        {'a','b','c'}
    };
    Solution s;

    for (int i = 0; i < vchars.size(); i++) {
        s.printVec(vchars[i]);
        int output = s.compress(vchars[i]);
        cout << "Compressed string length: " << output << endl;
    }
    return 0;
}

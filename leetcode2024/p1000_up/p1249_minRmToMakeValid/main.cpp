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
Runtime 11 ms Beats 99.04%
Memory 12.23 MB Beats 86.96%
*/
    string minRemoveToMakeValid(string s) {
        string res = "";
        int left = 0;
        for (auto c : s) {
            if (c == '(') {
                left++;
            } else if (c == ')') {
                if (left == 0) // Don't add charactor
                    continue;
                left--;
            }
            res += c;
        }
        if (left == 0)
            return res;
        for (int i = res.length(); i >= 0; i--) {
            if (left == 0)
                break;
            if (res[i] == '(') {
                left--;
                res.erase(res.begin()+i);
            }
        }
        return res;
    }

};

int main()
{
    vector<string> vs = { "lee(t(c)o)de)", "a)b(c)d", "))((" };
    Solution s;

    for (auto str : vs) {
        cout << "Orig: " << str << endl;
        string output = s.minRemoveToMakeValid(str);
        cout << "Output : " << output << endl;
    }
    return 0;
}

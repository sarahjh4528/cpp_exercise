/*
Constraints:

1 <= s.length <= 20
s consists of digits only.
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

    vector<string> restoreIpAddresses(string s) {
        int slen = s.length();
        if (slen < 4)
            return {};
        vector<string> res;
        for (int i = 0; i < 3; i++) {
            string s1 = s.substr(0, i+1);
            if ((s1.length() > 1 && s1[0] == '0') || stoi(s1) > 255)
                break;
            for (int j = i+1; j < i+4 && j < slen-2; j++) {
                string s2 = s.substr(i+1, j-i);
                if ((s2.length() > 1 && s2[0] == '0') || stoi(s2) > 255)
                    break;
                for (int k = j+1; k < j+4 && k < slen-1; k++) {
                    string s3 = s.substr(j+1, k-j);
                    string s4 = s.substr(k+1);
                    if (s4.length() > 3 || stoi(s3) > 255 || stoi(s4) > 255)
                        continue;
                    if ((s3.length() > 1 && s3[0] == '0') || (s4.length() > 1 && s4[0] == '0'))
                        continue;
                    string curip = s1 + "." + s2 + "." + s3 + "." + s4;
                    res.push_back(curip);
                }
            }
        }
        return res;
    }
};

int main()
{
    vector<string> vs = {
        "25525511135",
        "0000",
        "101023"
    };
    Solution s;

    for (auto str : vs) {
        vector<string> output = s.restoreIpAddresses(str);
        s.printVec(output);
    }
    return 0;
}

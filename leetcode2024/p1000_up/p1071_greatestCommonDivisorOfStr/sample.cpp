#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
    }
};

int main()
{
    vector<string> vstr1 = { "ABCABC", "ABABAB", "LEET" };
    vector<string> vstr2 = { "ABC", "ABAB", "CODE" };
    Solution s;

    for (int i = 0; i < vstr1.size(); i++) {
        cout << "Str1: " << vstr1[i] << ", str2: " << vstr2[i] << endl;
        string output = s.gcdOfStrings(vstr1[i], vstr2[i]);
        cout << "gcd string: " << output << endl;
    }
    return 0;
}

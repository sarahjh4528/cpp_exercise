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
Runtime 7 ms Beats 7.50%
Memory 11.54 MB Beats 6.26%

Fastest solution utilizes variables instead of unordered_map
*/
    bool isNumber(string s) {
        unordered_map<string, int> cmap;
        for (int i = 0; i < s.length(); i++) {
            if (!isdigit(s[i]) && s[i] != '.' && s[i] != '+' && s[i] != '-' && tolower(s[i]) != 'e')
                return false;
            if (s[i] == '+' || s[i] == '-') {
                if (!(i == 0 || (cmap.count("expo") && i == cmap["expo"] + 1)))
                    return false;
                cmap["sign"] = i;
            }
            if (s[i] == '.') {
                if (cmap.count("dot") || cmap.count("expo")) // No multiple dots, no '.' after 'e/E'
                    return false;
                cmap["dot"] = i;
            }
            if (isdigit(s[i])) {
                if (cmap.count("expo"))
                    cmap["digitback"] = i;
                else
                    cmap["digitfront"] = i;
                continue;
            }
            if (tolower(s[i]) == 'e') {
                if (cmap.count("expo") || !cmap.count("digitfront"))
                    return false;
                cmap["expo"] = i;
            }
        }
        if (cmap.count("expo") && !cmap.count("digitback"))
            return false;
        if ((cmap.count("dot") || cmap.count("sign")) && !cmap.count("digitfront"))
            return false;

        return true;
    }

};

int main()
{
    vector<string> vs = {
        "0", "e", ".", "2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10",
        "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789",
        "abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"         // invalid
    };
    Solution s;

    for (auto str : vs) {
        cout << "Input string: " << str << endl;
        bool output = s.isNumber(str);
        cout << "Is number: " << output << endl;
    }

    return 0;
}

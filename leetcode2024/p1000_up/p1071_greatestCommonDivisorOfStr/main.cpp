#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
/*
1 <= str1.length, str2.length <= 1000
str1 and str2 consist of English uppercase letters.

Design:
If there exist gcd string for str1 and str2, then
str1 = n(gcd)
str2 = m(gcd)

Therefore, str1 + str2 = str2 + str1
Once confirmed str1 and str2 contain gcd str, can find out gcd str by
call "gcd" function to find out greatest common divisor of str1 and str2 length.
*/

/*
Runtime 0 ms Beats 100.00%
Memory 9.79 MB Beats 46.95%
*/
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1)
            return "";
        int gcdlen = gcd(str1.length(), str2.length());
        return str1.substr(0, gcdlen);
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

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
0 <= s.length <= 200
s consists of English letters (lower-case and upper-case), digits (0-9), ' ', '+', '-', and '.'.
*/
/*
Runtime 0 ms Beats 100.00%
Memory 9.18 MB Beats 57.48%

Time: O(n)
Space : O(1)
*/
    int myAtoi(string s) {
        int res = 0, sign = 1, slen = s.length(), i = 0;
        while (i < slen && s[i] == ' ')
            i++;
        if (i == slen)
            return res;
        if (s[i] == '+' || s[i] == '-') {
            sign = (s[i] == '-')? -1 : 1;
            i++;
        }
        int limit = INT_MAX/10;
        while (i < slen) {
            if (s[i] < '0' || s[i] > '9')
                return res * sign;
            if (res > limit || (res == limit && s[i]-'0' > 7))
                return (sign == -1)? INT_MIN : INT_MAX;
            res = res * 10 + (s[i]-'0');
            i++;
        }
        return res * sign;
    }
};

int main()
{
    vector<string> vs = {
        "42",
        " -042",
        "1337c0d3",
        "0-1",
        "words and 987"
    };
    Solution s;

    for (auto str : vs) {
        int output = s.myAtoi(str);
        cout << "myStoi(" << str << ") = " << output << endl;
    }

    return 0;
}

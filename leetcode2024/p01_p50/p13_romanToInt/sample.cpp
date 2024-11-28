/*
Constraints:

1 <= s.length <= 15
s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
It is guaranteed that s is a valid roman numeral in the range [1, 3999].
*/
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

    int romanToInt(string s) {
    }
};

int main()
{
    vector<string> vs = { "III", "LVIII", "MCMXCIV" };
    Solution s;

    for (auto str : vs) {
        int output = s.romanToInt(str);
        cout << "Input : " << str << endl;
        cout << "Output : " << output << endl;
        
    }
    return 0;
}

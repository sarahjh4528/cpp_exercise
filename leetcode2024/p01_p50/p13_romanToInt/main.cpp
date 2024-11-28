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
    unordered_map<char, int> rmap = {
        {'M', 1000},{'D', 500},{'C', 100},{'L', 50},{'X', 10},{'V', 5},{'I', 1}
    };
public:
    void printVec(vector<int>& v) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

/*
Runtime 15 ms Beats 14.50%
Memory 12.07 MB Beats 76.71%

Time: O(N)
Space: O(1) unordered_map utilizes constant memory
*/
    int romanToInt(string s) {
        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            if (i+1 < s.length() && rmap[s[i]] < rmap[s[i+1]])
                res -= rmap[s[i]];
            else
                res += rmap[s[i]];
        }
        return res;
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

/*
Constraints:

1 <= num <= 3999
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

/*
Fastest solution same design, but declare vector<pair<int, string>> as hash table
*/
    string intToRoman(int num) {
        vector<int> vals = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> syms = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string res = "";
        int i = 0;
        while (num > 0) {
            while (num >= vals[i]) {
                res += syms[i];
                num -= vals[i];
            }
            i++;
        }
        return res;
    }

/*
Runtime 9 ms Beats 22.03%
Memory 12.86 MB Beats 46.00%
// This is exactly same implementation as fastest solution.
    string intToRoman(int num) {
        vector<pair<int, string>> nsmap = {
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"}
        };
        string res = "";
        for (auto& [val, rom] : nsmap) {
            while (num >= val) {
                res += rom;
                num -= val;
            }
        }
        return res;
    }
*/
};

int main()
{
    vector<int> vnum = { 3749, 58, 1994 };
    Solution s;
    
    for (auto n : vnum) {
        cout << n << endl;
        string output = s.intToRoman(n);
        cout << "Roman string: " << output << endl;
    }
    return 0;
}

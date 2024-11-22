/*
Constraints:

1 <= s.length <= 1000
s consists of lowercase English letters.
*/
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
    void countPalindrom(string& s, int left, int right, int& res) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            res++;
            left--;
            right++;
        }
    }
public:
    void printVec(vector<int>& v) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

/*
Design: scan through s pos, left--, right++
odd case, left=right=i cover pos 1,3,5,7...
even case, left=i, right=i+1 cover pos 2,4,6,8...

Time complexity: O(n)
odd case O(n) + even case O(n)
*/
    int countSubstrings(string s) {
        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            // odd case
            countPalindrom(s, i, i, res);
            // even case
            countPalindrom(s, i, i+1, res);
        }
        return res;
    }

};

int main()
{
    Solution s;

    vector<int> input = {1,2,3,4,5,6};
    s.printVec(input);
    return 0;
}

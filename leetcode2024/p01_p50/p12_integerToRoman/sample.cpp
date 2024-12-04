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

    string intToRoman(int num) {
    }
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

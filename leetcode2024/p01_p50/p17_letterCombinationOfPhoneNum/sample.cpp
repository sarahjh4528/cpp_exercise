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

/*
0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
*/
    vector<string> letterCombinations(string digits) {
    }
};

int main()
{

    vector<string> vdigits = { "23", "", "2" };
    Solution s;

    for (auto digits : vdigits) {
        cout << digits << endl;
        vector<string> output = s.letterCombinations(digits);
        cout << "Letter combinations: " << endl;
        s.printVec(output);
    }
    return 0;
}

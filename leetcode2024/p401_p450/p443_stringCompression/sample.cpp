#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    void printVec(vector<char>& v) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

/*
1 <= chars.length <= 2000
chars[i] is a lowercase English letter, uppercase English letter, digit, or symbol.
*/
    int compress(vector<char>& chars) {
    }
};

int main()
{
    vector<vector<char>> vchars = {
        {'a','a','b','b','c','c','c'},
        {'a'},
        {'a','b','b','b','b','b','b','b','b','b','b','b','b'},
        {'a','b','c'}
    };
    Solution s;

    for (int i = 0; i < vchars.size(); i++) {
        s.printVec(vchars[i]);
        int output = s.compress(vchars[i]);
        cout << "Compressed string length: " << output << endl;
    }
    return 0;
}

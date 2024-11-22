/*
Constraints:

1 <= s.length <= 1000
s consists of lowercase English letters.
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

    int countSubstrings(string s) {
    }

};

int main()
{
    Solution s;

    vector<int> input = {1,2,3,4,5,6};
    s.printVec(input);
    return 0;
}

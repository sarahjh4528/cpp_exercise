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
1 <= s.length <= 30
s consists of lowercase English letters, digits, and square brackets '[]'.
s is guaranteed to be a valid input.
All the integers in s are in the range [1, 300].
*/
/*
TODO: Implement recursive function
*/
    string decodeString(string s) {
    }
};

int main()
{
    vector<string> vs = {
        "3[a]2[bc]",
        "3[a2[c]]",
        "2[abc]3[cd]ef"
    };
    Solution s;

    for (auto str : vs) {
        cout << "Orig str: " << str << endl;
        string output = s.decodeString(str);
        cout << "After decode: " << output << endl;
    }
    return 0;
}

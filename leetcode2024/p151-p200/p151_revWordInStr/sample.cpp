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
1 <= s.length <= 10^4
s contains English letters (upper-case and lower-case), digits, and spaces ' '.
There is at least one word in s.
*/
    string reverseWords(string s) {
    }
};

int main()
{
    vector<string> vs = {
        "the sky is blue",
        "  hello world  ",
        "a good   example"
    };
    Solution s;

    for (auto str : vs) {
        cout << "Orig str: " << str << endl;
        string output = s.reverseWords(str);
        cout << "After reverse: " << output << endl;
    }
    return 0;
}

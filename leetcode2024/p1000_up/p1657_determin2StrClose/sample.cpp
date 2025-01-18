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
1 <= word1.length, word2.length <= 10^5
word1 and word2 contain only lowercase English letters.
*/
    bool closeStrings(string word1, string word2) {
    }
};

int main()
{
    vector<string> vword1 = {
        "abc",
        "a",
        "cabbba"
    };
    vector<string> vword2 = {
        "bca",
        "aa",
        "abbccc"
    };
    Solution s;

    for (int i = 0; i < vword1.size(); i++) {
        cout << "Str1: " << vword1[i] << ", str2: " << vword2[i] << endl;
        bool output = s.closeStrings(vword1[i], vword2[i]);
        cout << "Str1 and str2 are close: " << output << endl;
    }

    return 0;
}

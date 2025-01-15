#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
public:
/*
1 <= s.length <= 10^5
s consists of lowercase English letters.
1 <= k <= s.length
*/
    int maxVowels(string s, int k) {
    }
};

int main()
{
    vector<string> vstr = {
        "abciiidef",
        "aeiou",
        "leetcode",
        "zpuerktejfp"
    };
    vector<int> vk = {3,2,3,3};
    Solution s;

    for (int i = 0; i < vk.size(); i++) {
        cout << "Input str: " << vstr[i] << endl;
        int output = s.maxVowels(vstr[i], vk[i]);
        cout << "Max vowel in len " << vk[i] << ": " << output << endl;
    }

    return 0;
}

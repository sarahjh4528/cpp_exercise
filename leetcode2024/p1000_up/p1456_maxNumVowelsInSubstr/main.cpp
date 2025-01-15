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
/*
Runtime 3 ms Beats 89.96%
Memory 13.25 MB Beats 33.23%

Time: O(n), Space: O(1)
*/
    int maxVowels(string s, int k) {
        int res = 0;
        for (int i = 0; i < k; i++) {
            if (isVowel(s[i]))
                res++;
        }
        if (res == k)
            return res;
        int curCnt = res;
        for (int i = k; i < s.length(); i++) {
            if (isVowel(s[i]))
                curCnt++;
            if (isVowel(s[i-k]))
                curCnt--;
            res = max(res, curCnt);
            if (res == k)
                return res;
        }
        return res;
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

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
/*
Runtime 22 ms Beats 57.09%
Memory 23.24 MB Beats 91.31%

Time: O(n+m), n: word1 length, m : word2 length.
      Loop through freq1 and freq2, and sorting take O(1) due to constant length (26)

Space: O(1)
*/
    bool closeStrings(string word1, string word2) {
        if (word1.length() != word2.length())
            return false;

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);
        for (auto c : word1)
            freq1[c-'a']++;
        for (auto c : word2)
            freq2[c-'a']++;
        for (int i = 0; i < 26; i++) {  // Make sure word1 and word2 contain same chars
            if ((freq1[i] && !freq2[i]) || (freq2[i] && !freq1[i]))
                return false;
        }

        // If same chars, and same frequency, with the 2 rules, we can convert.
        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());
        return freq1 == freq2;
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

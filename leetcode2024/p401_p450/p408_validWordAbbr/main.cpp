/*
Runtime 0 ms Beats 100.00%
Memory 7.80 MB Beats 65.74%
*/
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int wi = 0, ai = 0;
        int wlen = word.length(), alen = abbr.length();
        while (wi < wlen && ai < alen) {
            if (word[wi] == abbr[ai]) {
                wi++;
                ai++;
                continue;
            }
            if (!isdigit(abbr[ai]) || abbr[ai] == '0')
                return false;
            int skip = 0;
            while (ai < alen && isdigit(abbr[ai])) {
                skip = skip * 10 + (abbr[ai]-'0');
                ai++;
            }
            wi += skip;
        }
        return (ai == alen && wi == wlen);
    }
};

int main()
{
    vector<string> words = {
        "internationalization"
    };
    vector<string> abbrs = {
        "i12iz4n"
    };
    Solution s;

    for (int i = 0; i < words.size(); i++) {
        cout << "word: " << words[i] << endl;
        cout << "abbr: " << abbrs[i] << endl;
        bool output = s.validWordAbbreviation(words[i], abbrs[i]);
        cout << "Is valid word abbreviation: " << output << endl;
    }
    return 0;
}

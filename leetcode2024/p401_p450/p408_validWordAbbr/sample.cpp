#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
    }
};

int main()
{
    vector<string> words = {
        "internationalization",
        "apple",
        "abbde",
        "internationalization"
    };
    vector<string> abbrs = {
        "i12iz4n",
        "a2e",
        "a1b01e",
        "i5a11o1"
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

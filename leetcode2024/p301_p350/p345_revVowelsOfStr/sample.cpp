#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
    bool isVowel(char c) {
        char cl = tolower(c);
        return (cl == 'a' || cl == 'e' || cl == 'i' || cl == 'o' || cl == 'u');
    }
public:
/*
1 <= s.length <= 3 * 10^5
s consist of printable ASCII characters.
*/
    string reverseVowels(string s) {
    }
};

int main()
{
    vector<string> vs = {
        "IceCreAm",
        "leetcode",
    };
    Solution s;

    for (auto str : vs) {
        cout << "Orig str: " << str << endl;
        string output = s.reverseVowels(str);
        cout << "After vowels swaping: " << output << endl;
    }

    return 0;
}

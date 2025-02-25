#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
    bool isVowel(char c) {
        char uc = toupper(c);
        return (uc == 'A' || uc == 'E' || uc == 'I' || uc == 'O' || uc == 'U');
    }
public:
/*
1 <= s.length <= 3 * 10^5
s consist of printable ASCII characters.
*/
/*
Runtime 0 ms Beats 100.00%
Memory 10.24 MB Beats 82.00%
*/
    string reverseVowels(string s) {
        int i = 0, j = s.length()-1;
        while (i < j) {
            while (i < j && !isVowel(s[i]))
                i++;
            while (i < j && !isVowel(s[j]))
                j--;
            swap(s[i], s[j]);
            i++;
            j--;
        }
        return s;
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

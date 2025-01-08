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
/*
Runtime 0 ms Beats 100.00%
Memory 10.14 MB Beats 74.98%
*/
    string reverseVowels(string s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            while (i < j && !isVowel(s[i]))
                i++;
            while (i < j && !isVowel(s[j]))
                j--;
            if (i < j) {
                swap(s[i], s[j]);
                i++;
                j--;
            }
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

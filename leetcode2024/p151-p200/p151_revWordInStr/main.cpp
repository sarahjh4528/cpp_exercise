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
/*
Runtime 0 ms Beats 100.00%
Memory 10.47 MB Beats 54.84%
*/
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        string res = "";
        int i = 0, j = 0, size = s.length();
        while (i < size && j < size) {
            while (i < size && s[i] == ' ')
                i++;
            if (i == size)
                break;
            j = i+1;
            while (j < size && s[j] != ' ')
                j++;
            string tmp = s.substr(i, j-i);
            reverse(tmp.begin(), tmp.end());
            res += ' ' + tmp;
            i = j+1;
        }
        return res.substr(1);
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

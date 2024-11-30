/*
Constraints:

1 <= words.length <= 300
1 <= words[i].length <= 20
words[i] consists of only English letters and symbols.
1 <= maxWidth <= 100
words[i].length <= maxWidth
*/
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
    string formStr(vector<string>& words, int from, int to, int curlen, int maxWidth, bool last) {
        int spaceNum = to - from;
        if (spaceNum == 0)
            return words[from] + string(maxWidth-words[from].length(), ' ');

        int remLen = maxWidth - (curlen - spaceNum);
        int spaces = (maxWidth - (curlen - spaceNum)) / spaceNum;
        string curline = "";
        for (int i = from ; i < to; i++) {
            curline += (last)? words[i] + ' ' : words[i] + string(spaces, ' ');
            if (remLen % spaceNum && i == from && !last)
                curline += ' ';
        }
        curline += words[to];
        return curline;
    }

public:
    void printVec(vector<string>& v) {
        for (auto i : v)
            cout << i << endl;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int i = 0;
        bool last = false;
        while (i < words.size()) {
            int from = i;
            int curlen = words[i].length();
            int j = i;
            while (j+1 < words.size() && curlen+1+words[j+1].length() <= maxWidth) {
                j++;
                curlen += 1 + words[j].length();
            }
            if (j == words.size()-1)
                last = true;
            
            res.push_back(formStr(words, from, j, curlen, maxWidth, last));
            i = j + 1;
        }
        return res;
    }
};

int main()
{
    vector<vector<string>> vwords = {
        {"This", "is", "an", "example", "of", "text", "justification."},
        {"What","must","be","acknowledgment","shall","be"},
        {"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"},
    };
    vector<int> vmaxWidth = {16, 16, 20};
    Solution s;

    for (int i = 0; i < vwords.size(); i++) {
        vector<string> output = s.fullJustify(vwords[i], vmaxWidth[i]);
        s.printVec(output);
    }
    return 0;
}

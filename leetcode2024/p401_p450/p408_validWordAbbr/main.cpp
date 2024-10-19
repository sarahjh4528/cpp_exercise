/*
Runtime 0 ms Beats 100.00%
Memory 7.64 MB Beats 86.34%
*/
class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0, j = 0, skip = 0;
        while (i < word.length() && j < abbr.length()) {
            if (word[i] == abbr[j]) {
                i++;
                j++;
                continue;
            }
            if (!isdigit(abbr[j]) || abbr[j] == '0')
                return false;
            skip = 0;
            while (j < abbr.length() && isdigit(abbr[j])) {
                skip = skip * 10 + (abbr[j]-'0');
                j++;
            }
            while (i < word.length() && skip > 0) {
                if (word[i] != ' ')
                    skip--;
                i++;
            }
        }
        return i == word.length() && j == abbr.length() && skip == 0;
    }
};

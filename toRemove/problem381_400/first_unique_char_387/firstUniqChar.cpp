#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
// Runtime : 40ms
// A better solution, record each char occur frequency in charIndex, then loop through string s again,
// and check frequency, if == 1, return its index, otherwise return -1.
    int firstUniqChar(string s) {
        int charIndex[26] = {0};
        int sLen = s.length();

        for (int i = 0; i < s.length(); ++i) {
            int cur = s[i] - 'a';
            if (charIndex[cur])
                charIndex[cur] = sLen + 1;
            else
                charIndex[cur] = i + 1;
        }
        int ret = -1;
        for (int j = 0; j < 26; ++j) {
            if (charIndex[j] != 0 && charIndex[j] != sLen+1)
                ret = (ret == -1)? charIndex[j]-1 : min(ret, charIndex[j]-1);
        }
        return ret;
    }
};
int main()
{
#if 0
    string str = "leetcode";
    string str = "loveleetcode";
#endif
    string str = "loveleetcode";
    Solution s;

    int firstUniq = s.firstUniqChar(str);
    cout << str << endl;
    cout << "First unique char index: " << firstUniq << endl;
    return 0;
}

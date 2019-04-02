#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    int firstUniqChar(string s) {
        int charIndex[26] = {0};

        for (int i = 0; i < s.length(); ++i) {
            int cur = s[i] - 'a';
            if (charIndex[cur] == -1)
                continue;
            if (charIndex[cur])
                charIndex[cur] = -1;
            else
                charIndex[cur] = i+1;
        }

        int ret = s.length();
        for (int j = 0; j < 26; ++j) {
            if (charIndex[j] != -1 && charIndex[j])
                ret = min(charIndex[j]-1, ret);
        }
        return (ret == s.length())? -1 : ret;
    }
};
int main()
{
    vector<string> vStr = {
        "leetcode",
        "loveleetcode"
    };
    Solution s;

    for (auto str : vStr) {
        int firstUniq = s.firstUniqChar(str);
        cout << str << endl;
        cout << "First unique char index: " << firstUniq << endl;
    }
    return 0;
}

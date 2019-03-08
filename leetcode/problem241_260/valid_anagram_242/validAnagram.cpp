#include<iostream>

using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;

        int lc[26] = {0};
        for (int i = 0; i < s.length(); ++i) {
            ++lc[s[i] - 'a'];
            --lc[t[i] - 'a'];
        }

        for (int j = 0; j < 26; ++j) {
            if (lc[j] != 0)
                return false;
        }
        return true;
    }
};
int main()
{
#if 0
    string s = "anagram", t = "nagaram";
    string s = "an", t = "nagaram";
    string s = "car", t = "cat";
#endif
    string s = "car", t = "cat";
    Solution so;

    bool isAng = so.isAnagram(s, t);
    cout << s << " & " << t << " are anagram : " << isAng << endl;
    return 0;
}

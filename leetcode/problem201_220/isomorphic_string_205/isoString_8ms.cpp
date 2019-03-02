#include<iostream>

using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t) {
        char sMap[256] = {};
        char tMap[256] = {};

        for (int i = 0; i < s.length(); ++i) {
            if (sMap[s[i]] && sMap[s[i]] != t[i])
                return false;
            if (tMap[t[i]] && tMap[t[i]] != s[i])
                return false;

            if (!sMap[s[i]])
                sMap[s[i]] = t[i];

            if (!tMap[t[i]])
                tMap[t[i]] = s[i];
        }
        return true;
    }
};
int main()
{
#if 0
    string str1 = "egg";
    string str2 = "add";

    string str1 = "foo";
    string str2 = "bar";

    string str1 = "bar";
    string str2 = "foo";

    string str1 = "paper";
    string str2 = "title";
#endif
    string str1 = "bar";
    string str2 = "foo";

    Solution s;
    bool isIso = s.isIsomorphic(str1, str2);
    cout << str1 << " & " << str2 << ", is isomorphic : " << isIso << endl;
    return 0;
}

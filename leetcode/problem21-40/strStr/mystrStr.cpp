#include<iostream>
  
using std::cout;
using std::endl;
using std::string;

class Solution
{
public:
    int strStr(string haystack, string needle) {
        if (haystack.length() < needle.length())
            return -1;

        if (needle.empty())
            return 0;

#if 0
// Very slow!
        for (int i = 0; i != haystack.length(); ++i) {
            int hIndex = i, nIndex = 0;
            while (hIndex < haystack.length() && nIndex < needle.length()) {
                if (haystack[hIndex] != needle[nIndex]) {
                    break;
                }
                if (nIndex == needle.length() - 1) {
                    return i;
                } else {
                    ++hIndex;
                    ++nIndex;
                }
            }
        }
#endif
        /* haystack.length() - needle.length() is auto promoted to unsigned
         * Therefore, need to make sure haystack.length > needle.length before doing
         * following evaluate, otherwise the result is a big number.
         */
        for (int i = 0; i <= haystack.length() - needle.length(); ++i) {
            if (haystack[i] == needle[0] &&
                haystack.substr(i, needle.length()) == needle)
                return i;
        }
        return -1;
    }
};

int main()
{
#if 0
    string hs = "hello";
    string nd = "ll";

    string hs = "aaaaa";
    string nd = "caa";

    string hs = "a";
    string nd = "a";

    string hs = "aaa";
    string nd = "aaaa";
#endif
    string hs = "hello";
    string nd = "ll";

    Solution s;
    int outIndex = s.strStr(hs, nd);
    cout << "haystack: " << hs << endl;
    cout << "needle: " << nd << endl;
    cout << "OutIndex: " << outIndex << endl;

    return 0;
}


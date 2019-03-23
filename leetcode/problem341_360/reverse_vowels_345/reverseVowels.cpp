#include<iostream>
#include<unordered_map>
#include<algorithm>

using namespace std;

unordered_map<char, int> vDict = {
    {'a', 1},
    {'e', 1},
    {'i', 1},
    {'o', 1},
    {'u', 1},
    {'A', 1},
    {'E', 1},
    {'I', 1},
    {'O', 1},
    {'U', 1},
};
class Solution
{
public:
    string reverseVowels(string s) {
        if (s.empty())
            return s;

        int mf = 0, mb = s.length() - 1;
        while (mf < mb) {
            while (mf < mb && !vDict[s[mf]])
                ++mf;
            while (mf < mb && !vDict[s[mb]])
                --mb;
            if (mf < mb)
                swap(s[mf], s[mb]);
            ++mf;
            --mb;
#if 0
            if (vDict[s[mf]]) {
                if (vDict[s[mb]]) {
                    swap(s[mf], s[mb]);
                    --mb;
                    ++mf;
                } else {
                    --mb;
                }
            } else {
                ++mf;
            }
#endif
        }
        return s;
    }
};
int main()
{
#if 0
    string input = "hello";
    string input = "leetcode";
#endif
    string input = "leetcode";

    Solution s;
    string output = s.reverseVowels(input);
    cout << input << endl;
    cout << output << endl;
    return 0;
}

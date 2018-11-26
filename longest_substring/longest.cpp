#include<iostream>
#include<string>
#include<unordered_set>

using namespace std;

#define LOOPSIZE 7
string sampleStr[LOOPSIZE] = {
"abcabcbb",
"bbbbb",
"pwwkew",
"",
" ",
"au",
"dvdf"
};

class Solution {
private:
    void printMySet(unordered_set<char> mySet) {
        for (const auto& elem : mySet) {
            cout << elem << ", ";
        }
        cout << endl;
    }
public:
    int lengthOfLongestSubstring(string s) {
        int longestLen = 0;
        int strLen = s.length();
        if (strLen == 0)
            return 0;
        if (strLen == 1)
            return 1;

        for (int i = 0; i <= strLen - 2; i++) {
            unordered_set<char> uSet = {s[i]};
            for (int j = i+1; j <= strLen - 1; j++) {
                if (uSet.find(s[j]) != uSet.end()) {
                    // duplicate char, calculate length and continue
                    if (longestLen < uSet.size())
                        longestLen = uSet.size();
                        break;
                } else {
                    uSet.insert(s[j]);
                }
            }
            if (longestLen < uSet.size())
                longestLen = uSet.size();
        }
        return longestLen;
    }
};

int main()
{
    for (int i = 0; i < LOOPSIZE; i++) {
        string inputStr = sampleStr[i];
        cout << inputStr << endl;
        Solution s;
        int longestSubStringLen = s.lengthOfLongestSubstring(inputStr);
        cout << longestSubStringLen << endl;
    }

    return 0;
}

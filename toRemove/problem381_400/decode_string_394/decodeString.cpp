#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool isDigit(char c) {
        return (c >= '1' && c <= '9');
    }
    void decodeStringHelper(string& s, int& pos, string& dstr) {
        int repeat = 0;
        while (s[pos] != '[') {
            repeat = repeat * 10 + s[pos] - '0';
            ++pos;
        }
        
        ++pos;    // '['
        string decodedStr = "";
        while (s[pos] != ']') {
            if (isDigit(s[pos])) {
                string decodedSubStr = "";
                decodeStringHelper(s, pos, decodedSubStr);
                decodedStr.append(decodedSubStr);
            } else {
                decodedStr.push_back(s[pos]);
            }
            ++pos;
        }
        while (repeat) {
            dstr.append(decodedStr);
            --repeat;
        }
    }

    string decodeString(string s) {
        if (s.empty())
            return "";
        string res;
        int pos = 0;
        while (pos < s.length()) {
            if (!isDigit(s[pos])) {
                res.push_back(s[pos]);
            } else {
                string decString = "";
                decodeStringHelper(s, pos, decString);
                res.append(decString);
            }
            ++pos;
        }
        return res;
    }
};

int main()
{
    vector<string> encodedStrs = {
        "3[a]2[bc]",
        "3[a2[c]]",
        "2[abc]3[cd]ef",
        "100[leetcode]"
    };

    Solution s;
    for (auto str : encodedStrs) {
        string decodedStr = s.decodeString(str);
        cout << str << endl;
        cout << "Decoded: " << decodedStr << endl;
    }

    return 0;
}

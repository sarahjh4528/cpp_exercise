#include<iostream>
#include<sstream>
#include<unordered_map>

using namespace std;

class Solution
{
public:
    bool wordPattern(string pattern, string str) {
        istringstream is(str);
        string temp = "";
        
        int i = 0, pLen = pattern.length();
        unordered_map<char, string> csMap;
        unordered_map<string, char> scMap;
        while (i < pLen && (is >> temp)) {
            char c = pattern[i];
            unordered_map<char, string>::const_iterator it = csMap.find(c);
            if (it != csMap.end()) {
                if (csMap[c] != temp)
                    return false;
            } else {
                csMap[c] = temp;
            }
            if (scMap[temp]) {
                if (scMap[temp] != c)
                    return false;
            } else {
                scMap[temp] = c;
            }
            ++i;
        }
        if (i < pLen || is >> temp)
            return false;
        return true;
    }
};
int main()
{
#if 0
    string p = "abba";
    string str = "dog cat cat dog";
    string p = "abba";
    string str = "dog cat cat fish";
    string p = "abba";
    string str = "dog cat cat";
    string p = "abb";
    string str = "dog cat cat dog";
#endif
    string p = "abba";
    string str = "dog dog dog dog";
    Solution s;
    bool matchPattern = s.wordPattern(p, str);
    cout << "Pattern: " << p << endl;
    cout << "str: " << str << endl;
    cout << "Match: " << matchPattern << endl;
    return 0;
}

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
private:
    bool isPalindrome(string& s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (s[i] != s[j])
                return false;
            ++i;
            --j;
        }
        return true;
    }
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> wMap;
        int len = words.size();
        for (int i = 0; i < len; ++i) {
            string key = words[i];
            reverse(key.begin(), key.end());
            wMap[key] = i;
        }

        vector<vector<int>> res;
        // Corner case, wMap key == "", it can pair with any palindrome string, but cannot
        // enter following second loop, as words[i].size is 0.
        if (wMap.find("") != wMap.end()) {
            for (int i = 0; i < len; ++i) {
                if (words[i] != "" && isPalindrome(words[i]))
                    res.push_back({wMap[""], i});
            }
        }

        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < words[i].size(); ++j) {
                string left = words[i].substr(0, j);
                string right = words[i].substr(j, words[i].size() - j);
                if (wMap.find(left) != wMap.end() && isPalindrome(right) && wMap[left] != i)
                    res.push_back({i, wMap[left]});
                if (wMap.find(right) != wMap.end() && isPalindrome(left) && wMap[right] != i)
                    res.push_back({wMap[right], i});
            }
        }
        return res;
    }
};

int main()
{
    vector<vector<string>> vWords = {
        {"abcd","dcba","lls","s","sssll"},
        {"bat","tab","cat"},
        {"a",""}
    };

    Solution s;
    for (auto words : vWords) {
        vector<vector<int>> indices = s.palindromePairs(words);
        cout << "Input: " << endl;
        for (auto word : words)
            cout << word << " ";
        cout << endl;
        for (auto ind : indices) {
            for (auto p : ind)
                cout << p << " ";
            cout << endl;
        }
    }
    return 0;
}

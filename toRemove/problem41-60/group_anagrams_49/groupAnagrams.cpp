#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
         if (strs.empty()) return {};
         if (strs.size() == 1) return {strs};

         vector<vector<string>> ret;
         unordered_map<string, int> strIndex;
         strIndex[""] = 0;
         int index = 1;
         for (int i = 0; i < strs.size(); ++i) {
             string str = strs[i];
             sort(str.begin(), str.end());
             if (strIndex[str]) {
                 ret[strIndex[str]-1].push_back(strs[i]);
             } else {
                 strIndex[str] = index;
                 ++index;
                 vector<string> vec(1, strs[i]);
                 ret.push_back(vec);
             }
         }
         return ret;
    }
};

int main()
{
    vector<string> words = {
        "eat", "tea", "tan", "ate", "nat", "bat"
    };

    Solution s;
    vector<vector<string>> groupedAnagrams = s.groupAnagrams(words);
    for (auto v : groupedAnagrams) {
        for (auto str : v)
            cout << str << " ";
        cout << endl;
    }
    return 0;
}

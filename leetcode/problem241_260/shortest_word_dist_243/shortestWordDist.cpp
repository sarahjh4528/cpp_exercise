/*
 * Given a list of words and two words word1 and word2, return the shortest distance
 * between these two words in the list.
 * 
 * Example:
 * Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
 * 
 * Input: word1 = “coding”, word2 = “practice”
 * Output: 3
 * Input: word1 = "makes", word2 = "coding"
 * Output: 1
 */
// Runtime: 53.13%, memory: 18.18%
#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int wLen = words.size();
        int ret = wLen;
        unordered_map<string, int> wMap;

//        cout << "word1 : " << word1 << ", word2: " << word2 << endl;
        for (int i = 0; i < wLen; ++i) {
            if (words[i] == word1) {
                wMap[word1] = i;
//        cout << "wMap[word1] = " << wMap[word1] << endl;
                if (wMap.find(word2) != wMap.end())
                    ret = min(ret, abs(wMap[word1] - wMap[word2]));
            } else if (words[i] == word2) {
                wMap[word2] = i;
//        cout << "wMap[word2] = " << wMap[word2] << endl;
                if (wMap.find(word1) != wMap.end())
                    ret = min(ret, abs(wMap[word1] - wMap[word2]));
            }
        }
        
        return ret;
    }
};

int main()
{
    vector<string> words = {
        "practice", "makes", "perfect", "coding", "makes"
    };

    vector<vector<string>> word12 = {
        {"coding", "practice"},
        {"makes", "coding"},
    };

    Solution s;
    for (auto ws : word12) {
        int shortestDist = s.shortestDistance(words, ws[0], ws[1]);
        cout << ws[0] << ", " << ws[1] << ", shortest distance: " << shortestDist << endl;
    }

    return 0;
}

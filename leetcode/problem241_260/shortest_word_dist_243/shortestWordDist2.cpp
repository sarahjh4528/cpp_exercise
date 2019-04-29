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
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int pos1 = -1, pos2 = -1;
        int wLen = words.size();
        int ret = wLen;

        for (int i = 0; i < wLen; ++i) {
            if (words[i] == word1) {
                pos1 = i;
                if (pos2 >= 0)
                    ret = min(ret, pos1 - pos2);
            } else if (words[i] == word2) {
                pos2 = i;
                if (pos1 >= 0)
                    ret = min(ret, pos2 - pos1);
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

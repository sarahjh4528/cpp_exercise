/**
 * Your WordDesign a class which receives a list of words in the constructor, and implements a
 * method that takes two words word1 and word2 and return the shortest distance between these two
 * words in the list. Your method will be called repeatedly many times with different parameters. 
 * Example:
 * Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
 * 
 * Input: word1 = "coding", word2 = "practice"
 * Output: 3
 * Input: word1 = "makes", word2 = "coding"
 * Output: 1
 * Note:
 * 
 * You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
 * Distance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(words);
 * int param_1 = obj->shortest(word1,word2);
 */
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class WordDistance {
private:
    unordered_map<string, vector<int>> wdMap;
public:
    WordDistance(vector<string>& words) {
        for (int i = 0; i < words.size(); ++i)
            wdMap[words[i]].push_back(i);
    }

    int shortest(string word1, string word2) {
        vector<int>& pos1 = wdMap[word1];
        vector<int>& pos2 = wdMap[word2];
        int len1 = pos1.size(), len2 = pos2.size();
        int ret = max(pos1[len1-1], pos2[len2-1]);
        int i1 = 0, i2 = 0;
        while (i1 < len1 && i2 < len2) {
            ret = min(ret, abs(pos1[i1] - pos2[i2]));
            if (pos1[i1] < pos2[i2])
                ++i1;
            else
                ++i2;
        }
        return ret;
    }
};

int main()
{
    vector<string> words = {
        "practice", "makes", "perfect", "coding", "makes"
    };

    vector<vector<string>> inputs = {
        {"coding", "practice"},
        {"makes", "coding"}
    };

    WordDistance ws(words);

    for (auto wdIn : inputs) {
        int shortestDist = ws.shortest(wdIn[0], wdIn[1]);
        cout << wdIn[0] << " & " << wdIn[1] << " shortest distance: " << shortestDist << endl;
    }
    return 0;
}

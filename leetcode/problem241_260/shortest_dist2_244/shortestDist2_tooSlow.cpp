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
#include<algorithm>

using namespace std;

class WordDistance {
private:
    vector<string> wordList;
public:
    void printWords() {
        if (wordList.empty())
            return;
        for (auto word : wordList)
            cout << word << " ";
        cout << endl;
    }

    WordDistance(vector<string>& words) : wordList(words.size()) {
        copy(words.begin(), words.end(), wordList.begin());
    }

    int shortest(string word1, string word2) {
        int pos1 = -1, pos2 = -1;
        int wLen = wordList.size();
        int ret = wLen;
        for (int i = 0; i < wLen; ++i) {
            if (wordList[i] == word1) {
                pos1 = i;
                if (pos2 >= 0)
                    ret = min(ret, pos1 - pos2);
            } else if (wordList[i] == word2) {
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

    vector<vector<string>> inputs = {
        {"coding", "practice"},
        {"makes", "coding"}
    };

    WordDistance ws(words);

    ws.printWords();

    for (auto wdIn : inputs) {
        int shortestDist = ws.shortest(wdIn[0], wdIn[1]);
        cout << wdIn[0] << "& " << wdIn[1] << " shortest distance: " << shortestDist << endl;
    }
    return 0;
}

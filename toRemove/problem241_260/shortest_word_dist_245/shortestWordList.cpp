/*
 * Given a list of words and two words word1 and word2, return the shortest
 * distance between these two words in the list.
 * 
 * word1 and word2 may be the same and they represent two individual words in the list.
 * Example:
 * Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
 * 
 * Input: word1 = “makes”, word2 = “coding”
 * Output: 1
 * Input: word1 = "makes", word2 = "makes"
 * Output: 3
 * Note: You may assume word1 and word2 are both in the list.
 */
/*
 16ms, faster than 95%.
 4ms solution is add two helper function, sameWordsDist and diffWordsDist, and justify
 whether word1 == word2 before enter for loop, then call different function.
 */
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int wLen = words.size();
        int pos1 = -1, pos2 = -1, ret = wLen;
        for (int i = 0; i < wLen; ++i) {
            if (words[i] == word1) {
                if (word1 == word2 && pos1 != -1)    // word1 == word2
                    ret = min(ret, i - pos1);
                else if (pos2 != -1)   // word1 != word2
                    ret = min(ret, i - pos2);
                pos1 = i;
            } else if (word1 != word2 && words[i] == word2) {
                // word1 != word2
                if (pos1 != -1)
                    ret = min(ret, i - pos1);
                pos2 = i;
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
    string word1 = "makes", word2 = "coding";
//    string word1 = "makes", word2 = "makes";

    Solution s;
    int shortestDist = s.shortestWordDistance(words, word1, word2);
    cout << "Shortest distance between " << word1 << " & " << word2
         << " is : " << shortestDist << endl;
    
    return 0;
}

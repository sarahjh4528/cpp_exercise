/* Given an input string , reverse the string word by word.
 * 
 * Example:
 * Input:  ["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]
 * Output: ["b","l","u","e"," ","i","s"," ","s","k","y"," ","t","h","e"]
 *
 * Note:
 * A word is defined as a sequence of non-space characters.
 * The input string does not contain leading or trailing spaces.
 * The words are always separated by a single space.
 */
// 60ms, 99.29%; 16.3MB, 78.67%
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
private:
    void reverseHelper(vector<char>& str, int start, int end) {
        while (start < end) {
            swap(str[start++], str[end--]);
        }
    }
public:
    void reverseWords(vector<char>& str) {
        int strLen = str.size();
        reverse(str.begin(), str.end());

        int i = 0, start = 0;
        for (; i < strLen; ++i) {
            if (str[i] != ' ')
                continue;
            reverseHelper(str, start, i-1);
            start = i + 1;
        }
        reverseHelper(str, start, i-1);
    }
};

int main()
{
    vector<vector<char>> inputs = {
        {'t','h','e',' ','s','k','y',' ','i','s',' ','b','l','u','e'},
        {'T','h','e',' ','w','o','r','d','s',' ','a','r','e'},
    };
    Solution s;
    for (auto input : inputs) {
        cout << "Input: " << endl;
        for (auto c : input)
            cout << c << ",";
        cout << endl;

        s.reverseWords(input);

        cout << "Output: " << endl;
        for (auto c : input)
            cout << c << ",";
        cout << endl;
    }
    return 0;
}

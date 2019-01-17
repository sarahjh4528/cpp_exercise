#include<iostream>
#include<vector>
#include<unordered_map>
#include<deque>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::unordered_map;
using std::deque;

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> dict = {
            {'(', ')'},
            {'{', '}'},
            {'[', ']'}
        };

        if (s.empty())
            return true;

        deque<char> cStack;
        for (auto c : s) {
            switch (c) {
                case '(':
                case '{':
                case '[':
                    cStack.push_back(dict[c]);
                    break;
                default:
                    if (!cStack.empty() && cStack.back() == c)
                        cStack.pop_back();
                    else
                        return false;
            }
        }
        if (cStack.empty())
            return true;
        else
            return false;
    }
};

int main()
{
    vector<string> input = {
        "()",
        "()[]{}",
        "([",
        "([)]",
        "{[]}",
        "]"
    };

    Solution s;
    for (auto str : input) {
        cout << "Input string: " << str << endl;
        bool isMatch = s.isValid(str);
        cout << "Match: " << isMatch << endl;
    }
    return 0;
}


#include<iostream>

using std::cout;
using std::endl;
using std::string;

class Solution
{
public:
    void reverseStringWithinIndex(string &str, int start, int end) {
        if (start == end)
            return;

        while (start < end) {
            char temp = str[end];
            str[end] = str[start];
            str[start] = temp;
            ++start;
            --end;
        }
    }

    void reverseSentence(string& inStr) {
        if (inStr.empty())
            return;

        // Reverse entire string
        reverseStringWithinIndex(inStr, 0, inStr.length() - 1);

        int wordStart = -1, wordEnd = -1;
        for (int i = 0; i < inStr.length(); ++i) {
            if (inStr[i] == ' ' || (i == inStr.length() - 1)) {
                if (wordStart != -1) {
                    wordEnd = (inStr[i] == ' ')? i - 1 : i;
                    reverseStringWithinIndex(inStr, wordStart, wordEnd);
                    wordStart = wordEnd = -1;
                }
                continue;
            } else if (wordStart == -1) {
                wordStart = i;
            }
        }
    }
};

int main()
{
    string str = "This is a sentence that needs to be reversed.";

    Solution s;
    cout << str << endl;
    cout << str.length() << endl;
    s.reverseSentence(str);
    cout << "After reverse" << endl;
    cout << str << endl;
    return 0;
}

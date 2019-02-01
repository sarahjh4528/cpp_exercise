#include<iostream>

using std::cout;
using std::endl;
using std::string;

class Solution
{
public:
    int lengthOfLastWord(string s) {
        if (s.empty())
            return 0;

        int len = 0;
        for (int i = s.length() - 1; i >= 0; --i) {
            if (s[i] != ' ') {
                ++len;
            } else {
                if (len)
                    return len;
            }
        }
        return len;
    }
};
int main()
{
    string str = "Hello World";

    Solution s;
    int len = s.lengthOfLastWord(str);
    cout << len << endl;
    return 0;
}

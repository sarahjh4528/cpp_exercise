#include<iostream>
#include<string>

using std::cout;
using std::endl;
using std::string;
using std::to_string;

class Solution
{
public:
    string countAndSay(int n) {
        if (n == 1)
            return "1";

        string prevStr = countAndSay(n-1);
        string ret = "";
        int cnt = 1;
        int strLen = prevStr.length();
        for (int i = 0; i != strLen; ++i) {
            if (i + 1 < strLen) {
                if (prevStr[i + 1] == prevStr[i]) {
                    ++cnt;
                } else {
                    ret = ret + to_string(cnt) + prevStr[i];
                    cnt = 1;
                }
            } else {
                ret = ret + to_string(cnt) + prevStr[i];
            }
        }
        return ret;
    }
};

int main()
{
    int n = 5;

    Solution s;
    string csStr = s.countAndSay(n);
    cout << "n: " << n << " , string: " << csStr << endl;
    return 0;
}

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
        int cnt = 0;
        for (int i = 0; i != prevStr.length(); ++i) {
            if (i == 0) {
                ++cnt;
            } else {
                if (prevStr[i] == prevStr[i-1]) {
                    ++cnt;
                } else {
                    ret = ret + to_string(cnt) + prevStr[i-1];
                    cnt = 1;
                }
            }
            if (i == prevStr.length() - 1)
                ret = ret + to_string(cnt) + prevStr[i];
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

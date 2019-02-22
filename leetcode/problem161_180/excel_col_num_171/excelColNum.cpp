#include<iostream>
#include<climits>

using namespace std;

class Solution
{
public:
    int titleToNumber(string s) {
        if (s.empty())
            return 0;

        unsigned long long ret = 0;
        unsigned long long mp = 1;
        for (int i = s.length() - 1; i >= 0; --i) {
            ret += (s[i] - 'A' + 1) * mp;
            mp *= 26;
        }
        return (int)ret;
    }
};

int main()
{
#if 0
    string str = "AB";
    string str = "A";
    string str = "ZY";
    string str = "CFDGSXM";
#endif
    string str = "CFDGSXM";
    Solution s;

    int num = s.titleToNumber(str);
    cout << "Title : " << str << ", num " << num << endl;
    return 0;
}

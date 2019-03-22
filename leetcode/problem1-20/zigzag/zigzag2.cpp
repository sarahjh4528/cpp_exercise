#include<iostream>

using namespace std;

class Solution
{
public:
    string convert(string s, int numRows) {
        string ret = "";
        int cycle = (numRows<<1) - 2;    // Top and bottom row only has one elem
        cout << cycle << endl;
        for (int i = 0; i < numRows; ++i) {
            int idx = i, interval;
            interval = (i == 0 || i == numRows - 1)? cycle : cycle - 2*i;
            while (idx < s.length()) {
                ret += s[idx];
                idx += interval;
                interval = (i == 0 || i == numRows - 1)? cycle : cycle - interval;
            }
        }
        return ret;
    }
};
int main()
{
    string inStr = "ABCDEFGHIJKLMNOPQR";    // AGMBFHLNRCEIKOQDJP
    int row = 4;

    Solution s;
    string outStr = s.convert(inStr, row);
    cout << inStr << ", Length: " << inStr.length() << endl;
    cout << "Expected:  " << "AGMBFHLNRCEIKOQDJP" << endl;
    cout << outStr << ", Length: " << outStr.length() << endl;
    return 0;
}

#include<iostream>

using namespace std;

class Solution
{
public:
    const string TITLECHAR = "ZABCDEFGHIJKLMNOPQRSTUVWXY";
    string convertToTitle(int n) {
        string ret = "";
        while (n > 0) {
            int remainder = n % 26;
            ret = TITLECHAR[remainder] + ret;
            n -= (remainder == 0)? 26 : remainder;
            n /= 26;
        }
        return ret;
    }
};

int main()
{
#if 0
    int colNum = 1;
    int colNum = 28;
    int colNum = 701;
#endif
    int colNum = 28;
    Solution s;

    string title = s.convertToTitle(colNum);
    cout << "Num : " << colNum << ", title : " << title << endl;
    return 0;
}

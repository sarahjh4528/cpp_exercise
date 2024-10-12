#include<iostream>
#include<sstream>
#include<vector>

using namespace std;

class Solution
{
public:
    int calculateHelper(string& s, int& i, int len) {
        int res = 0;
        bool isAdd = true;
        while (i < len) {
            int num = 0;
            while (i < len && isdigit(s[i])) {
                num = num*10 + (s[i++] - '0');
            }
            res = (isAdd)? res + num : res - num;
            if (i == len)
                return res;
            switch (s[i]) {
                case '+':
                    isAdd = true;
                    break;
                case '-':
                    isAdd = false;
                    break;
                case '(':
                    ++i;
                    if (isAdd)
                        res += calculateHelper(s, i, len);
                    else
                        res -= calculateHelper(s, i, len);
                    break;
                case ')':
                    return res;
            }
            ++i;
        }
        return res;
    }
    int calculate(string s) {
        if (s.empty())
            return 0;

        // Remove all spaces
        istringstream iss(s);
        ostringstream oss;
        string temp;
        while (iss >> temp) {
            oss << temp;
        }
        temp = oss.str();
        int index = 0;
        int res = calculateHelper(temp, index, temp.size());
        return res;
    }
};
int main()
{
    vector<string> vStr = {
        "1 + 1",
        " 2-1 + 2 ",
        "(1+(4+5+2)-3)+(6+8)",
        " 30",
        "1-(5)",
    };

    Solution s;
    for (auto str : vStr) {
        int result = s.calculate(str);
        cout << str << " = " << result << endl;
    }
    return 0;
}

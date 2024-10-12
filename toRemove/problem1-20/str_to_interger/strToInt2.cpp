#include<iostream>
#include<vector>
#include<climits>

using std::cout;
using std::endl;
using std::string;
using std::vector;

class Solution {
public:
    int myAtoi(string str) {
        long long ret = 0;
        bool isNegative = false;
        bool numStart = false;

        for (int i = 0; i < str.length(); ++i) {
            if (str[i] == ' ' && !numStart)
                continue;
            if ((str[i] == '-' || str[i] == '+') && !numStart) {
                isNegative = (str[i] == '-')? true : false;
                numStart = true;
                continue;
            }
            if (str[i] <= '9' && str[i] >= '0') {
                numStart = true;
                ret = ret*10 + (str[i] - '0');
                if (isNegative && ret - 1 >= INT_MAX)
                    return INT_MIN;
                if (ret > INT_MAX)
                    return INT_MAX;
            } else {
                break;
            }
        }
        ret = (isNegative)? -ret : ret;
        return (int)ret;
    }
};

int main()
{
    vector<string> vs = {
        "12345",
        "+456",
        "-347",
        "",
        "   ",
        "-  ",
        "345eir",
        "i-45dier",
        "-",
        "123456789",
        "9987654321",
        "-987654321",
        "-9987654321",
        "9223372036854775808",
        "-9223372036854775808",
        "0-1",
        "+-2",
        "-2147483648"
    };

    Solution sol;
    for (auto s : vs) {
        int result = sol.myAtoi(s);
        cout << "Input: " << s << endl;
        cout << "result: " << result << endl;
    }
    return 0;
}

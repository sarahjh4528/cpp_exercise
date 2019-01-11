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
        if (str.length() == 0) {
            return 0;
        }

        long long ret = 0;
        bool numStart = false;
        bool addMinus = false;
        for (auto const c : str) {
            // This is bad! This condition is evaluated in each loop. Can be avoided.
            if (c == ' ' && !numStart)
                continue;
            // This is bad! This condition is evaluated in each loop. Can be avoided.
            if (ret == 0 && (c == '+' || c == '-') && !numStart) {
                addMinus = (c == '-')? true : false;
                numStart = true;
                continue;
            }
            // Use isdigit instead.
            if (c >= '0' && c <= '9') {
                ret = ret * 10 + (c - '0');
                if (ret > INT_MAX) {
                    return (addMinus)? INT_MIN : INT_MAX;
                }
                numStart = true; // If move above 2 if conditions out, then this can be removed.
            } else {
                break;
            }
        }
        if (addMinus)
            ret = -ret;

        // Following codes are redundant, already handled in loop.
        if (ret > INT_MAX) 
            return INT_MAX;
        if (ret < INT_MIN)
            return INT_MIN;
        
        return ret;
    }
#if 0
// A Better solution, run in 8ms.
int myAtoi(string str)
{
    //skip the whitespaces
    int beginIndex = 0;
    for (; beginIndex != str.size() && str[beginIndex] == ' '; ++beginIndex);
    if (beginIndex == str.size()) return 0;

    //skip the sign
    bool isPosNum = true;
    if (str[beginIndex] == '-')
    {
        ++beginIndex;
        isPosNum = false;
    }
    else if (str[beginIndex] == '+') ++beginIndex;
    else if (!isdigit(str[beginIndex])) return 0;

    long long resNum = 0;
    for (int i = beginIndex; i < str.size(); ++i)
    {
        if (!isdigit(str[i])) break;
        resNum = resNum * 10 + (str[i] - '0');
        if (resNum > INT_MAX) return (isPosNum ? INT_MAX : INT_MIN);
    }

    return isPosNum ? resNum : (-1 * resNum);
}
#endif
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
        "0-1"
    };

    Solution sol;
    for (auto s : vs) {
        int result = sol.myAtoi(s);
        cout << "Input: " << s << endl;
        cout << "result: " << result << endl;
    }
    cout << INT_MAX << endl;
    cout << INT_MIN << endl;
    return 0;
}

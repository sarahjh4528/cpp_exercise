#include<iostream>
#include<string>

using std::cout;
using std::endl;
using std::string;
using std::to_string;

class Solution
{
public:
    int toInt(char a) {
        return a - '0';
    }

    string addBinary(string a, string b) {
        if (a.empty() || b.empty()) {
            return (a.empty())? b : a;
        }
        string ret;
        string::reverse_iterator aIt, bIt;
        int carry = 0;
        for (aIt = a.rbegin(), bIt = b.rbegin(); aIt != a.rend() && bIt != b.rend(); ++aIt, ++bIt) {
            if (toInt(*aIt) & toInt(*bIt)) {
                ret = (carry)? "1" + ret : "0" + ret;
                carry = 1;
            } else {
                int sum = toInt(*aIt) | toInt(*bIt);
                ret = (sum & carry)? "0" + ret : to_string(sum + carry) + ret;
                carry = (sum & carry)? 1 : 0;
            }
        }
        while (aIt != a.rend()) {
            int aInt = toInt(*aIt);
            ret = ((aInt != carry) && aInt | carry)? "1" + ret : "0" + ret;
            carry = (aInt & carry)? 1 : 0;
            ++aIt;
        }
        while (bIt != b.rend()) {
            int bInt = toInt(*bIt);
            ret = ((bInt != carry) && bInt | carry)? "1" + ret : "0" + ret;
            carry = (bInt & carry)? 1 : 0;
            ++bIt;
        }
        ret = (carry)? "1" + ret : ret;
        return ret;
    }
};
int main()
{
#if 0
    string a = "11";
    string b = "1";

    string a = "1010";
    string b = "1011";

    string a = "1111";
    string b = "1111";

    string a = "100";
    string b = "110010";

    string a = "101111";
    string b = "10";
#endif
    string a = "101111";
    string b = "10";

    Solution s;
    string sum = s.addBinary(a, b);
    cout << sum << endl;
    return 0;
}


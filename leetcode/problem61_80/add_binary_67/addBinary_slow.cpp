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
        if (a.empty() || b.empty())
            return (a.empty())? b : a;

        int aLen = a.length(), bLen = b.length();
        int shortLen = (aLen > bLen)? bLen : aLen;
        int carry = 0;
        int sum = 0;
        string ret = "";
        int index = 0;
        while (index < shortLen) {
            sum = toInt(a[aLen-index-1]) + toInt(b[bLen-index-1]) + carry;
            if (sum > 1) {
                carry = 1;
                ret = to_string(sum - 2) + ret;
            } else {
                carry = 0;
                ret = to_string(sum) + ret;
            }
            ++index;
        }

        if (aLen == bLen) {
            if (carry)
                return "1" + ret;
            else
                return ret;
        }
       
        string& remStr = (aLen > bLen)? a : b;
        index = remStr.length() - shortLen - 1;
        while (index >= 0) {
            sum = carry + toInt(remStr[index]);
            if (sum < 2)
                carry = 0;
            ret = ((sum > 1)? to_string(sum - 2) : to_string(sum)) + ret; 
            --index;
        }
        if (carry)
            ret = "1" + ret;
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
#endif
    string a = "11";
    string b = "1";

    Solution s;
    string sum = s.addBinary(a, b);
    cout << sum << endl;
    return 0;
}


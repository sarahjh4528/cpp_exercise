#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";

        int n1Len = num1.length(), n2Len = num2.length();
        int prodHolder[n1Len+n2Len] = {0};

        for (int i = n1Len -1; i >= 0; --i) {
            for (int j = n2Len -1; j >= 0; --j) {
                prodHolder[i+j+1] += (num1[i]-'0') * (num2[j]-'0');    // Add current product + result from prev cal
                prodHolder[i+j] += prodHolder[i+j+1]/10;     // Calculate and hold carry for next cal
                prodHolder[i+j+1] = prodHolder[i+j+1]%10;    // Hold result of current position
            }
        }

        string ret = "";
        int k = (prodHolder[0] == 0)? 1 : 0;
        while (k < n1Len + n2Len) {
            ret += to_string(prodHolder[k]);
            ++k;
        }
        return ret;
    }
};

int main()
{
#if 0
    string s1 = "2", s2 = "3";
    string s1 = "2", s2 = "5";
    string s1 = "123", s2 = "456";
#endif
    string s1 = "123", s2 = "456";

    Solution s;
    string output = s.multiply(s1, s2);
    cout << output << endl;

    return 0;
}

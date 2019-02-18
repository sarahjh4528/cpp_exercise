#include<iostream>

using namespace std;

class Solution
{
public:
    bool notValid(char c) {
        if ((c >= 'A'&& c <= 'Z') || (c >= '0' && c <= '9'))
            return false;
        else
            return true;

    }

    bool isPalindrome(string s) {
        if (s.empty())
            return true;

        int f = 0, b = s.length() - 1;
        while (f < b) {
            while (notValid(toupper(s[f])) && f < b)
                ++f;
            while (notValid(toupper(s[b])) && f < b)
                --b;

            if (toupper(s[f]) != toupper(s[b]))
                return false;
            ++f;
            --b;
        }
        return true;
    }
};

int main()
{
#if 0
    string str = "A man, a plan, a canal: Panama";
    string str = "";
    string str = "race a car";
    string str = ".,";
#endif
    string str = "0P";

    Solution s;
    bool isPal = s.isPalindrome(str);
    cout << "String : " << str << endl;
    cout << "Is palindrome: " << isPal << endl;
    return 0;
}

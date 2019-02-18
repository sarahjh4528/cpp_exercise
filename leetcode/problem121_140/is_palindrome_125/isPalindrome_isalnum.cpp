#include<iostream>

using namespace std;

class Solution
{
public:
    bool isPalindrome(string s) {
        if (s.empty())
            return true;

        int f = 0, b = s.length() - 1;
        while (f < b) {
            while (f < b && !isalnum(s[f]))
                ++f;
            while (f < b && !isalnum(s[b]))
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
    string str = "0P";
#endif
    string str = "A man, a plan, a canal: Panama";

    Solution s;
    bool isPal = s.isPalindrome(str);
    cout << "String : " << str << endl;
    cout << "Is palindrome: " << isPal << endl;
    return 0;
}

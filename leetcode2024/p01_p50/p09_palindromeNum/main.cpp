/*
Constraints:

-2^31 <= x <= 2^31 - 1
*/
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    void printVec(vector<int>& v) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

#if 1
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        string nstr = to_string(x);
        int l = 0, r = nstr.length()-1;
        while (l < r) {
            if (nstr[l] != nstr[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
#else
/* Without converting to string */
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;
        int rev = 0;
        while (x > rev) {
            rev = rev*10 + x % 10;
            x /= 10;
        }
        return x == rev || x == rev/10;
    }
#endif
};

int main()
{
    vector<int> vx = {121, -121, 10};
    Solution s;

    for (auto n : vx) {
        bool output = s.isPalindrome(n);
        cout << n << " is palindrome number: " << output << endl;
    }
    return 0;
}

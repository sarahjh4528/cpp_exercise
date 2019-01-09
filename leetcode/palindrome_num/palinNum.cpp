#include<iostream>
#include<vector>
#include<climits>

using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
#if 1
    bool isPalindrome(int x) {
        if (x < 0) // -121, palindrome is 121
            return false;

        long long revX = 0;
        int xCopy = x;
        while (xCopy) {
            revX = revX * 10 + xCopy % 10;
            xCopy /= 10;
        }
        if (revX > INT_MAX)
            return false;

        if (x == (int)revX)
            return true;
        else
            return false;
    }
#else
// A better solution. Only reverse to half
    bool isPalindrome(int x) {
        if(x<0|| (x!=0 &&x%10==0)) return false;
        int sum=0;
        while(x>sum)
        {
            sum = sum*10+x%10;
            x = x/10;
        }
        return (x==sum)||(x==sum/10);
    }
#endif
};

int main()
{
    vector<int> input = {
       123,
       121,
       10,
       -121,
       1234567899,
       987656789,
       0,

    };
    Solution s;

    for (auto i : input) {
        cout << "Input: " << i << endl;
        bool isPalin = s.isPalindrome(i);
        cout << "Is palindrome: " << isPalin << endl;
    }
    return 0;
}

/*
Runtime 0 ms Beats 100.00%
Memory 9.03 MB Beats 24.59%
*/
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        string xs = to_string(x);
        int left = 0, right = xs.length() - 1;
        while (left < right) {
            if (xs[left] != xs[right])
                return false;
            left++;
            right--;
        }
        return true;
    }

/*
Without converting to string.
*/
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) // negative num || 10, 20, 30, ...
            return false;

        int rev = 0;
        while (x > rev) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        return x == rev || x == rev / 10;
    }
};

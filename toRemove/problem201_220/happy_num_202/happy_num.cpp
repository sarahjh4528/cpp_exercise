#include<iostream>

using namespace std;

class Solution
{
private:
    int getSum(int n) {
        int sum = 0;
        while (n) {
            int remainder = n % 10;
            sum += remainder * remainder;
            n /= 10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        int slow = getSum(n);
        int fast = getSum(getSum(n));
        if (slow == 1 || fast == 1)
            return true;
        while (slow != fast) {
            slow = getSum(slow);
            fast = getSum(getSum(fast));
            if (slow == 1 || fast == 1)
                return true;
        }
        return false;
    }
};
int main()
{
#if 0
    int num = 19;
    int num = 2;
#endif
    int num = 1;

    Solution s;
    bool happy = s.isHappy(num);
    cout << "Num " << num << " is happy: " << happy << endl;
    return 0;
}

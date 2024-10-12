#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    int countPrimes(int n) {
        if (n <= 2)
            return 0;

        bool skip[n] = {false};         // 9.8  MB
//        vector<int> isPrime(n, 1);    // 21.6 MB
        int primeCount = 0;
        for (int i = 2; i < n; ++i) {
            if (!skip[i]) {
                ++primeCount;
                for (int j = (i << 1); j < n; j += i) {
                    skip[j] = true;
                }
            }
        }
        return primeCount;
    }
};
int main()
{
#if 0
    int n = 10;
    int n = 100;
    int n = 2;
    int n = 3;
#endif
    int n = 3;
    Solution s;

    int primeCount = s.countPrimes(n);
    cout << "Prime nums: " << primeCount << endl;
    return 0;
};

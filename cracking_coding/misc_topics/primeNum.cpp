#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;

void getPrime(vector<int>& primeNums, int range)
{
    for (int i = 3; i <= range; ++i) {
        bool isPrime = true;
        for (auto j : primeNums) {
            if (i % j == 0 && i / j > 1) {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
            primeNums.push_back(i);
    }
}

int main()
{
    int range = 100;
    vector<int> primeNums = {2};    // Prime numbers start from 2
    getPrime(primeNums, range);

    cout << "[" << primeNums[0];
    for (int i = 1; i < primeNums.size(); ++i) {
        cout << ", " << primeNums[i];
    }
    cout << "]" << endl;

    return 0;
}

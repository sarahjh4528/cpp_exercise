#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int>& prices) {
        int maxCur = 0, maxRet = 0;
        for (int i = 1; i < prices.size(); ++i) {
            maxCur = max(0, maxCur += (prices[i] - prices[i-1]));
            maxRet = max(maxCur, maxRet);
        }
        return maxRet;

    }
};

int main()
{
#if 0
    vector<int> inPrice = {7,1,5,3,6,4};
    vector<int> inPrice = {7,6,4,3,1};
#endif
    vector<int> inPrice = {7,6,4,3,1};
    Solution s;

    int maxReturn = s.maxProfit(inPrice);
    cout << "Max return: " << maxReturn << endl;
    return 0;
}

#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int>& prices) {
        int retProfit = 0;
        for (int i = 1; i < prices.size(); ++i)
            retProfit += max(prices[i] - prices[i-1], 0);
        return retProfit;
    }
};

int main()
{
#if 0 
    vector<int> priceList = {7,1,5,3,6,4};
    vector<int> priceList = {1,2,3,4,5};
    vector<int> priceList = {7,6,4,3,1};
    vector<int> priceList = {6,1,3,2,4,7};
#endif
    vector<int> priceList = {6,1,3,2,4,7};
    Solution s;
    int maxEarn = s.maxProfit(priceList);
    cout << "Max profit : " << maxEarn << endl;
    return 0;
}

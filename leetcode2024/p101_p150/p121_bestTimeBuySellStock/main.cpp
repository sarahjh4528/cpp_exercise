/*
Runtime 78 ms Beats 77.95%
Memory 95.84 MB Beats 99.69%
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx = 0, s = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            s = min(prices[i], s);
            mx = max(prices[i]-s, mx);
        }
        return mx;
    }
};

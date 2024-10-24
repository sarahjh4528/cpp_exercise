/*
Runtime 0 ms Beats 100.00%
Memory 71.36 MB Beats 79.80%
*/

class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int hi = heights.size() - 1;
        vector<int> res(1, hi);
        int curMax = heights[hi];
        for (int i = hi - 1; i >= 0; i--) {
            if (heights[i] > curMax) {
                res.push_back(i);
                curMax = heights[i];
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

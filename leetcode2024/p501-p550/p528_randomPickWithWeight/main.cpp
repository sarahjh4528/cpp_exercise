/*
Runtime 17 ms Beats 100.00%
Memory 45.27 MB Beats 70.95%
*/
class Solution {
    vector<int> prefixSum;
public:
    Solution(vector<int>& w) {
        prefixSum.resize(w.size());
        prefixSum[0] = w[0];
        for (int i = 1; i < w.size(); i++)
            prefixSum[i] = prefixSum[i-1] + w[i];
    }
    
    int pickIndex() {
#if 0
// This fails in some case.
        int ranNum = rand() % prefixSum.back();
        return lower_bound(begin(prefixSum), end(prefixSum), ranNum) - begin(prefixSum);
#else
        // generate a random number in the range of [0, 1]
        float randNum = (float) rand() / RAND_MAX;
        float target =  randNum * prefixSum.back();
        return lower_bound(begin(prefixSum), end(prefixSum), target) - begin(prefixSum);
#endif
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

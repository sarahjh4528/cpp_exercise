/*
Runtime 0 ms Beats 100.00%
Memory 17.67 MB Beats 20.48%
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (nums.size() == 1)
            return nums;
        unordered_map<int, int> freqMap;
        for (auto n : nums)
            freqMap[n]++;
        map<int, vector<int>, greater<int>> nCnt;
        for (auto it = freqMap.begin(); it != freqMap.end(); it++) {
            int curFreq = it->second;
            nCnt[curFreq].push_back(it->first);
        }
        vector<int> res;
        for (auto it = nCnt.begin(); it != nCnt.end(); it++) {
            vector<int>& curV = it->second;
            res.insert(res.end(), curV.begin(), curV.end());
            if (res.size() >= k)
                break;
        }
        if (res.size() > k)
            res.erase(res.end() - (res.size() - k), res.end());
        return res;
    }
};

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution
{
private:
    vector<vector<int>> res;
    vector<int> tmp;
public:
    void combinationSum2Helper(vector<int>& candidates, int start, int end, int target) {
        if (target == 0) {
            res.push_back(tmp);
            return;
        } else if (target < 0) {
            return;
        }

        for (int i = start; i <= end && candidates[i] <= target; ++i) {
            if (i > start && candidates[i] == candidates[i - 1])
                continue;
            target -= candidates[i];
            tmp.push_back(candidates[i]);
            combinationSum2Helper(candidates, i+1, end, target);
            target += candidates[i];
            tmp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        if (candidates.empty() || candidates[0] > target)
            return {};
        int i = candidates.size() - 1;
        while (candidates[i] > target)
            --i;

        combinationSum2Helper(candidates, 0, i, target);
        return res;
        
    }
};

int main()
{
    vector<int> nums = {10,1,2,7,6,1,5};
    int target = 8;
    Solution s;

    vector<vector<int>> res = s.combinationSum2(nums, target);
    for (auto v : res) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

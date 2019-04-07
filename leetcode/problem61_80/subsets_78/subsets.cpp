#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        res.push_back({});

        for (auto i : nums) {
            int resSize = res.size();
            for (int j = 0; j < resSize; ++j) {
                res.push_back(res[j]);
                res.back().push_back(i);
            }
        }
        return res;
    }
};

int main()
{
    vector<int> nums = {1, 2, 3};

    Solution s;
    vector<vector<int>> nSet = s.subsets(nums);
    for (auto n : nSet) {
        for (auto i : n)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}

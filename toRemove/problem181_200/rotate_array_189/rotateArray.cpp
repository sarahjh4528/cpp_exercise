#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    void printVec(vector<int>& nums) {
        for (auto i : nums)
            cout << i << " ";
        cout << endl;
    }
    void rotate(vector<int>& nums, int k) {
        k = k % (nums.size());
        if (!k)
            return;

        vector<int> helper(nums.size() - k);
        copy(nums.begin(), nums.begin() + (nums.size() - k), helper.begin());
        copy(nums.end() - k, nums.end(), nums.begin());
        copy(helper.begin(), helper.end(), nums.begin() + k);
    }
};

int main()
{
#if 0
    vector<int> input = {1,2,3,4,5,6,7};
    int k = 3;

    vector<int> input = {-1, -100, 3, 99};
    int k = 2;
#endif
    vector<int> input = {-1, -100, 3, 99};
    int k = 2;

    Solution s;
    s.rotate(input, k);
    s.printVec(input);
    return 0;
}

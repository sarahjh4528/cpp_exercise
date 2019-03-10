#include<iostream>
#include<vector>

using namespace std;

class NumArray
{
private:
    vector<int> sum;
public:
    NumArray(vector<int> nums) : sum(nums.size(), 0) {
        // OR : sum = vector<int> (nums.size(), 0);
        if (nums.empty())
            return;

        sum[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            sum[i] = sum[i-1] + nums[i];
        }
    }
    
    int sumRange(int i, int j) {
        if (sum.empty() || j >= sum.size())
            return 0;
        return (i == 0)? sum[j] : sum[j] - sum[i-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
    
int main()
{
#if 0
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
#endif
    vector<int> nums = {};

    NumArray obj(nums);
#if 0
    int i = 0, j = 2;
    int i = 2, j = 5;
    int i = 0, j = 5;
#endif
    int i = 0, j = 5;
    int param_1 = obj.sumRange(i, j);
    cout << "Sum of elements from " << i << " to j " << j << " is " << param_1 << endl;
    return 0;
}

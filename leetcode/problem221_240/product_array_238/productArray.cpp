#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        int forwardProd = 1, backwardProd = 1;

        for (int i = 0; i < n; ++i) {
            res[i] = forwardProd;
            forwardProd *= nums[i];
            res[n-1-i] *= backwardProd;
            backwardProd *= nums[n-1-i];
        }
        return res;
    }
};

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    Solution s;
    vector<int> prods = s.productExceptSelf(nums);

    for (auto p : prods)
        cout << p << " ";
    cout << endl;
    return 0;
}

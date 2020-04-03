#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void printVec(vector<int>& nums) {
        for (auto n : nums)
            cout << n << " ";
        cout << endl;
    }

#if 0
    // 20ms, 9.7MB. Not a good solution.
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k = k % size;
        if (k == 0)
            return;
        nums.insert(nums.end(), nums.begin(), nums.begin() + (size - k));
        nums.erase(nums.begin(), nums.begin() + (size - k));
    }
#else
    // 
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        if (size <= 1)
            return;

        k = k % size;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
#endif
};

int main()
{
    vector<vector<int>> inputs = {
        {1,2,3,4,5,6,7},
        {-1,-100,3,99},
        {-1},
    };
    vector<int> ks = {3, 2, 2};

    Solution s;
    for (int i = 0; i < inputs.size(); i++) {
        s.printVec(inputs[i]);
        s.rotate(inputs[i], ks[i]);
        s.printVec(inputs[i]);
    }
    return 0;
}

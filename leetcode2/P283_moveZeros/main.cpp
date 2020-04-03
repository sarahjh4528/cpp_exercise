#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void printVec(vector<int>& v) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

#if 0
    // 16ms, faster than 65%, memory less than 69%.
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        while (j < nums.size() && nums[j] != 0)
            j++;

        bool move = false;
        for (int i = j + 1; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[j] = nums[i];
                move = true;
                j++;
            }
        }
        if (!move)
            return;

        while (j < nums.size()) {
            nums[j] = 0;
            j++;
        }
    }
#else
    // Faster than 97%, mem less than 79%.
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != 0) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
    }
#endif
};

int main() {
    vector<int> input = {0, 1, 0, 3, 12};
//    vector<int> input = {1};

    Solution s;
    s.printVec(input);
    s.moveZeroes(input);
    s.printVec(input);

    return 0;
}

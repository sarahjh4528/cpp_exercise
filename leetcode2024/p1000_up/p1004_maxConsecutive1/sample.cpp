#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    void printVec(vector<int>& v) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

/*
Design: Find current max window, keep window size, increase window size only if zeros <= k,
otherwise move window to right (Increase left & right),
*/
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right;
        int n = nums.size();
        for (right = 0; right < n; right++) {
            // If we included a zero in the window we reduce the value of k.
            // Since k is the maximum zeros allowed in a window.
            if (nums[right] == 0) {
                k--;
            }
            // A negative k denotes we have consumed all allowed flips and window has
            // more than allowed zeros, thus increment left pointer by 1 to keep the window size same.
            if (k < 0) {
                // If the left element to be thrown out is zero we increase k.
                k += 1 - nums[left];
                left++;
            }
        }
        return right - left;
    }
};

int main()
{
    vector<vector<int>> input = {
        {1,1,1,0,0,0,1,1,1,1,0},
        {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1}
    };
    vector<int> vk = {2, 3};
    Solution s;

    for (int i = 0; i < vk.size(); i++) {
        s.printVec(input[i]);
        int output = s.longestOnes(input[i], vk[i]);
        cout << "Max consecutive ones: " << output << endl;
    }
    return 0;
}

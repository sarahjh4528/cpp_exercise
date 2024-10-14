/*
Runtime 15 ms Beats 84.69%
Memory 25.00 MB Beats 63.18%
Time: O(log(N)), Space: O(1)
*/
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
Design: Binary search on even index
Separate array to half, since there is only 1 single element, it should always be
in the odd number of elements.

0   1   2   3   4   5   6
1   1   2               // mid % 2 == 1, mid--, then compare nums[mid] & nums[mid+1], 1 & 1
1   2   2
1   1   2   2   3       // mid % 2 == 0, directly compare nums[mid] & nums[mid+1], 2 & 2
1   2   2   3   3
1   1   2   3   3
1   1   2   3   3   4   4 // mid%2==1, mid--, compare nums[mid] & nums[mid+1], 2 & 3
*/
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            int mid = low + (high-low)/2;
            if (mid % 2 == 1)
                mid--;
            if (nums[mid] == nums[mid+1])
                low = mid+2;
            else
                high = mid;
        }
        return nums[low];
    }
};

int main()
{
    vector<vector<int>> input = {
        {1,1,2,3,3,4,4,8,8},
        {3,3,7,7,10,11,11}
    };
    Solution s;

    for (auto nums : input) {
        s.printVec(nums);
        int output = s.singleNonDuplicate(nums);
        cout << "Single element: " << output << endl;
    }
    return 0;
}

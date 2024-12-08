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
Constraints:

1 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.
*/
    vector<int> topKFrequent(vector<int>& nums, int k) {

    }
};

int main()
{
    vector<vector<int>> input = {
        {1,1,1,2,2,3},
        {1}
    };
    vector<int> vk = {2,1};
    Solution s;

    for (auto nums : input) {
        s.printVec(nums);
        
    }
    return 0;
}

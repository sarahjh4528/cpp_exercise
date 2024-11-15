/*
Constraints:

1 <= nums.length <= 2 * 10^4
-2^31 <= nums[i] <= 2^31 - 1
target is an integer from nums.
At most 10^4 calls will be made to pick.
*/
#include<bits/stdc++.h>
#include<iostream>
#include<random>

using namespace std;

class Solution {
    unordered_map<int, vector<int>> nmap;   // num : vector<index>
public:
    void printVec(vector<int>& v) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

    Solution(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++)
            nmap[nums[i]].push_back(i);
    }
    
/*
Runtime 132 ms Beats 39.00%
Memory 66.19 MB Beats 32.78%
*/
    int pick(int target) {
        random_device rd;
        mt19937 gen(rd());
        int n = nmap[target].size();
        uniform_int_distribution<int> dist(1, n);
        int res = dist(gen);
        return nmap[target][res-1];
    }

};

int main()
{
    vector<int> nums = {1, 2, 3, 3, 3};
    vector<int> vt = {3,1,3};
    Solution s(nums);
    s.printVec(nums);

    for (auto t : vt) {
        int output = s.pick(t);
        cout << "Index of " << t << " : " << output << endl;
    }

    return 0;
}

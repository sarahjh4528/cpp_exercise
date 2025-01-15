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
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9
1 <= k <= 10^9
*/
/*
Runtime 105 ms Beats 37.10%
Memory 76.64 MB Beats 20.11%

Time: O(n), Space O(n)

Fastest solution utilize "sort", then use 2 pointers.
Time: O(nlog(n)), Space: O(1)
*/
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> nmap;
        int res = 0;
        for (auto n : nums) {
            if (nmap[k-n] > 0) {
                nmap[k-n]--;
                res++;
            } else {
                nmap[n]++;
            }
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> vnums = {
        {1,2,3,4},
        {3,1,3,4,3}
    };
    vector<int> vk = {5,6};
    Solution s;

    for (int i = 0; i < vk.size(); i++) {
        s.printVec(vnums[i]);
        int output = s.maxOperations(vnums[i], vk[i]);
        cout << "Max num of " << vk[i] << "-sum pairs: " << output << endl;
    }

    return 0;
}

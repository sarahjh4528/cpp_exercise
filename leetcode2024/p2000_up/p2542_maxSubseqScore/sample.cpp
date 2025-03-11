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
n == nums1.length == nums2.length
1 <= n <= 10^5
0 <= nums1[i], nums2[j] <= 10^5
1 <= k <= n
*/
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
    }
};

int main()
{
    vector<vector<int>> vnum1 = {
        {1,3,3,2},
        {4,2,3,1,1}
    };
    vector<vector<int>> vnum2 = {
        {2,1,3,4},
        {7,5,10,9,6}
    };
    vector<int> vk = {3,1};
    Solution s;

    for (int i = 0; i < vnum1.size(); i++) {
        s.printVec(vnum1[i]);
        s.printVec(vnum2[i]);
        long long output = s.maxScore(vnum1[i], vnum2[i], vk[i]);
        cout << "Maximum subseq score: " << output << endl;
    }
    return 0;
}

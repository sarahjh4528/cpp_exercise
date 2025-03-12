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
1 <= costs.length <= 10^5 
1 <= costs[i] <= 10^5
1 <= k, candidates <= costs.length
*/
    long long totalCost(vector<int>& costs, int k, int candidates) {
    }
};

int main()
{
    vector<vector<int>> vcosts = {
        {17,12,10,2,7,2,11,20,8},
        {1,2,4,1}
    };
    vector<int> vk = {3,3};
    vector<int> vcandidates = {4,3};
    Solution s;

    for (int i = 0; i < vk.size(); i++) {
        s.printVec(vcosts[i]);
        long long output = s.totalCost(vcosts[i], vk[i], vcandidates[i]);
        cout << "Total cost hire " << vk[i] << " workers: " << output << endl;
    }

    return 0;
}

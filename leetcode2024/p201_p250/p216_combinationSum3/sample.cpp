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
2 <= k <= 9
1 <= n <= 60
*/
    vector<vector<int>> combinationSum3(int k, int n) {
    }
};

int main()
{
    vector<int> vk = {3,3,4};
    vector<int> vn = {7,9,1};
    Solution s;

    for (int i = 0; i < vk.size(); i++) {
        cout << "k = " << vk[i] << ", n = " << vn[i] << endl;
        vector<vector<int>> output = s.combinationSum3(vk[i], vn[i]);
        for (auto row : output)
            s.printVec(row);
    }
    return 0;
}

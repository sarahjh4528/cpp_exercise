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

    int longestConsecutive(vector<int>& nums) {
    }
};

int main()
{
    vector<vector<int>> vnums = {
        {100,4,200,1,3,2},
        {0,3,7,2,5,8,4,6,0,1}
    };
    Solution s;

    vector<int> input = {1,2,3,4,5,6};
    s.printVec(input);
    return 0;
}

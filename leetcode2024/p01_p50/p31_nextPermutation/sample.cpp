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

    void nextPermutation(vector<int>& nums) {
    
    }
};

int main()
{
    vector<int> nums = {1,2,3};
    Solution s;

    for (int i = 0; i < 6; i++) {
        s.printVec(nums);
        s.nextPermutation(nums);
        cout << "Next permuation: " << endl;
        s.printVec(nums);
    }

    return 0;
}

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

    int minEatingSpeed(vector<int>& piles, int h) {
    }
};

int main()
{
    vector<vector<int>> vpiles = {
        {3,6,7,11},
        {30,11,23,4,20},
        {30,11,23,4,20}
    };
    vector<int> vh = {8, 5, 6};
    Solution s;
    for (int i = 0; i < vh.size(); i++) {
        s.printVec(vpiles[i]);
        int output = s.minEatingSpeed(vpiles[i], vh[i]);
        cout << "Minimum bananas " << output << " can finish in " << vh[i] << " hours." << endl;
    }

    return 0;
}

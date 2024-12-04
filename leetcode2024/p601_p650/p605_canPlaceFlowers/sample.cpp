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

    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    }
};

int main()
{
    vector<vector<int>> vflowerbed = {
        {1,0,0,0,1},
        {1,0,0,0,1}
    };
    vector<int> vn = {1,2};
    Solution s;

    for (int i = 0; i < vn.size(); i++) {
        s.printVec(vflowerbed[i]);
        bool output = s.canPlaceFlowers(vflowerbed[i], vn[i]);
        cout << "Can place flowers: " << output << endl;
    }

    return 0;
}

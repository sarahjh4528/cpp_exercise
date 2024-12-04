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
Runtime 0 ms Beats 100.00%
Memory 24.06 MB Beats 6.49%
*/
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        for (int i = 0; i < size; i++) {
            if (flowerbed[i] == 0) {
                bool left = (i == 0 || flowerbed[i-1] == 0);
                bool right = (i == size-1 || flowerbed[i+1] == 0);
                if (left && right) {
                    flowerbed[i] = 1;
                    n--;
                }
            }
        }
        return (n <= 0);
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

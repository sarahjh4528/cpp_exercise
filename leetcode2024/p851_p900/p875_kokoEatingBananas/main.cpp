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
Runtime 8 ms Beats 62.48%
Memory 21.64 MB Beats 78.15%

Fastest solution same design (Binary search)
*/
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        if (h == piles.size())
            return high;

        int res = high; // Max number in piles can definitely satisfy requirement
        while (low <= high) {
            int mid = (high + low)/2;
            long long hrs = 0;
            for (auto p : piles)
//                hrs += p/mid + (p%mid != 0);  // round up, Ex: 3/2 round up to 2
                hrs += ceil((double)pl / (double)mid);
            if (hrs <= h) {// hrs, can try smaller values
                res = min(res, mid);
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return res;
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

/*
Runtime 0 ms Beats 100.00%
Memory 33.87 MB Beats 88.90%
*/
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
Design:
Example : 1,2,3,4,5, find 4 cloest elements to 4 => {2,3,4,5}

Starting from index 0, ending index 5 - 4 = 1,
Check elements in sliding window with length 4.

Binary search: compare distance arr[mid] & 4
                                arr[mid+k] & 4
                            (element just outside window)
If mid is closer, move high to mid, if mid+k is closer, move low to mid+1 (mid is further, can exclude)

*/
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        if (n == 1 || n == k)
            return arr;

        int low = 0, high = n - k;
        while (low < high) {
            int mid = (high + low) / 2;
            if (x - arr[mid] <= arr[mid+k] - x)
                high = mid;
            else
                low = mid + 1;
        }
        vector<int> res(arr.begin()+low, arr.begin()+low+k);
        return res;
    }
};

int main()
{
    vector<vector<int>> varr = {
        {1,2,3,4,5},
        {1,1,2,3,4,5}
    };
    vector<int> vk = {4,4};
    vector<int> vx = {3, -1};
    Solution s;

    for (int i = 0; i < vk.size(); i++) {
        s.printVec(varr[i]);
        vector<int> output = s.findClosestElements(varr[i], vk[i], vx[i]);
        cout << vk[i] << " closest element to " << vx[i] << " : " << endl;
        s.printVec(output);
    }
    return 0;
}

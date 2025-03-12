/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
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
1 <= n <= 2^31 - 1
1 <= pick <= n
*/
/*
Runtime 3 ms Beats 17.30%
Memory 7.97 MB Beats 39.94%
*/
    int guessNumber(int n) {
        int low = 1, high = n;
        while (low <= high) {
            int mid = low + (high-low)/2;
            int res = guess(mid);
            if (res == 0)
                return mid;
            else if (res == -1)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return -1;
    }
};

int main()
{
    vector<int> vn = {10, 1, 2};
    vector<int> vpick = {6, 1, 1};
    Solution s;

    for (int i = 0; i < vn.size(); i++) {
        int output = s.guessNumber(
    }
    return 0;
}

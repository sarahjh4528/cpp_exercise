/*
Runtime 0 ms Beats 100.00%
Memory 12.43 MB Beats 12.55%
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
Design : Binary Search (Olog(n))
Array number range : 1 .. n

Index i     :   0  1  2  3  4
Sequence    :   1  2  3  4  5  6  7  8  9  10  11
num         :   2  3  4  7  11
Missing num :   1  1  1  3  6       Formula : arr[i] - (i+1)
Looking for :             5th missing number

We can do binary search on the array of "Missing num", Find index "low" and "high"

=> While loop stops when high < low, in this case
high = 3
low  = 4

We're looking for arr[high] + more, more = k-missing at high

Missing at high = arr[high] - (high + 1)

Final result = arr[high] + (k - (arr[high] - (high + 1)))
=> arr[high] + k - arr[high] + (high+1)
=> k + (high + 1), high+1 = low
=> low + k

*/

    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0, high = n - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (arr[mid] - (mid+1) < k)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low+k;
    }
};

int main()
{
    vector<vector<int>> input = {
        {2,3,4,7,11},
        {2,3,4,7,11},
        {1,2,3,4},
        {1,3}
    };
    vector<int> vk = {5,3,2,3};
    Solution s;

    for (int i = 0; i < vk.size(); i++) {
        s.printVec(input[i]);
        int output = s.findKthPositive(input[i], vk[i]);
        cout << vk[i] << "th missing number: " << output << endl;
    }

    return 0;
}

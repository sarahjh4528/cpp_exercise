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
n == spells.length
m == potions.length
1 <= n, m <= 10^5
1 <= spells[i], potions[i] <= 10^5
1 <= success <= 10^10
*/
#if 0
/*
Runtime 60 ms Beats 5.11%
Memory 125.20 MB Beats 5.93%

Fastest solution utilizes built_in function lower_bound.
*/
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size(), m = potions.size();
        sort(potions.begin(), potions.end());
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            int cur = m;
            int low = 0, high = m-1;
            while (low <= high) {
                int mid = (low+high)/2;
                if ((long long)spells[i] * potions[mid] >= success) {
                    cur = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            res[i] = m - cur;
        }
        return res;
    }
#endif
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size(), m = potions.size();
        sort(potions.begin(), potions.end());
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            int cur = m;
            long long minPotion = ceil(1.0 * success)/spells[i];
            auto index = lower_bound(potions.begin(), potions.end(), minPotion) - potions.begin();
            cout << "index = " << index << endl;
            res[i] = m - index;
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> vspells = {
        {5,1,3},
        {3,1,2}
    };
    vector<vector<int>> vpotions = {
        {1,2,3,4,5},
        {8,5,8}
    };
    vector<int> vsucc = {7, 16};
    Solution s;

    for (int i = 0; i < vspells.size(); i++) {
        s.printVec(vspells[i]);
        s.printVec(vpotions[i]);
        vector<int> output = s.successfulPairs(vspells[i], vpotions[i], vsucc[i]);
        cout << "Sucessful pairs: " << endl;
        s.printVec(output);
        cout << endl;
    }

    
    return 0;
}

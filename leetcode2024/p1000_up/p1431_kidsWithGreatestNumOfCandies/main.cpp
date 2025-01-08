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
n == candies.length
2 <= n <= 100
1 <= candies[i] <= 100
1 <= extraCandies <= 50
*/

/*
Runtime 0 ms Beats 100.00%
Memory 12.37 MB Beats 67.00%
*/
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        auto maxN = max_element(candies.begin(), candies.end());
        int size = candies.size();
        vector<bool> res(size, false);
        for (int i = 0; i < candies.size(); i++) {
            if (candies[i] + extraCandies >= *maxN)
                res[i] = true;
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> vcandies = {
        {2,3,5,1,3},
        {4,2,1,1,2},
        {12,1,12}
    };
    vector<int> vextraCandies = {3,1,10};
    Solution s;

    for (int i = 0; i < vcandies.size(); i++) {
        s.printVec(vcandies[i]);
        vector<bool> output = s.kidsWithCandies(vcandies[i], vextraCandies[i]);
        cout << "With extra candies " << vextraCandies[i] << endl;
        for (auto v : output)
            cout << v << " ";
        cout << endl;
    }
    return 0;
}

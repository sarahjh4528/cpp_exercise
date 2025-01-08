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

    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
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

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
1 <= temperatures.length <= 10^5
30 <= temperatures[i] <= 10^0
*/
/*
Runtime 9 ms Beats 96.38%
Memory 102.71 MB Beats 84.52%
*/
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int days = temperatures.size();
        vector<int> res(days, 0);
        int hottest = temperatures[days-1];
        for (int i = days-2; i >= 0; i--) {
            if (temperatures[i] >= hottest) {
                // Travel backward, current temp > hottest, impossible to get warmer.
                hottest = temperatures[i];
                continue;
            }
            int day = 1;
            while (temperatures[i] >= temperatures[i+day])
                day += res[i+day];
            res[i] = day;
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> vtemp = {
        {73,74,75,71,69,72,76,73},
        {30,40,50,60},
        {30,60,90}
    };
    Solution s;

    for (int i = 0; i < vtemp.size(); i++) {
        s.printVec(vtemp[i]);
        vector<int> output = s.dailyTemperatures(vtemp[i]);
        cout << "Days to wait to get warmer temperature." << endl;
        s.printVec(output);
    }

    return 0;
}

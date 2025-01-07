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
    vector<int> dailyTemperatures(vector<int>& temperatures) {
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

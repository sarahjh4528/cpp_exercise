#include<bits/stdc++.h>
#include<iostream>
#include<stack>

using namespace std;

class Solution {
public:
    void printVec(vector<int>& v) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

    vector<int> asteroidCollision(vector<int>& asteroids) {
    }
};

int main()
{
    vector<vector<int>> input = {
        {5,10,-5},
        {8,-8},
        {10, 2, -5},
    };
    Solution s;

    for (auto asteroids : input) {
        s.printVec(asteroids);
        vector<int> output = s.asteroidCollision(asteroids);
        cout << "After collision: " << endl;
        s.printVec(output);
    }
    return 0;
}

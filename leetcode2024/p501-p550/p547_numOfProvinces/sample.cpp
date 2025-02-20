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
1 <= n <= 200
n == isConnected.length
n == isConnected[i].length
isConnected[i][j] is 1 or 0.
isConnected[i][i] == 1
isConnected[i][j] == isConnected[j][i]
*/
    int findCircleNum(vector<vector<int>>& isConnected) {
    }
};

int main()
{
#if 0
    vector<vector<int>> connected = { {1,1,0}, {1,1,0}, {0,0,1} };
    vector<vector<int>> connected = { {1,0,0}, {0,1,0}, {0,0,1} };
#endif
    vector<vector<int>> connected = { {1,0,0}, {0,1,0}, {0,0,1} };
    Solution s;

    for (auto row : connected)
        s.printVec(row);

    int output = s.findCircleNum(connected);
    cout << "Num of provinces: " << output << endl;
    return 0;
}

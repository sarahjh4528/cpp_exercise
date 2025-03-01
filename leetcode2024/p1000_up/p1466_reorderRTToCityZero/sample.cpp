#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    void printVec(vector<int>& v) {
        for (auto i : v)
            cout << i << " ";
        cout << ", ";
    }

/*
NOTE: There is only one way to travel between two different cities
2 <= n <= 5 * 104
connections.length == n - 1
connections[i].length == 2
0 <= ai, bi <= n - 1
ai != bi
*/
    int minReorder(int n, vector<vector<int>>& connections) {
    }
};

int main()
{
#if 0
    vector<vector<int>> connections = { {0,1},{1,3},{2,3},{4,0},{4,5} };
    int n = 6;
    vector<vector<int>> connections = { {1,0},{1,2},{3,2},{3,4} };
    int n = 5;
    vector<vector<int>> connections = { {1,0},{2,0} };
    int n = 3;
#endif
    vector<vector<int>> connections = { {0,1},{1,3},{2,3},{4,0},{4,5} };
    int n = 6;
    Solution s;

    for (auto& row : connections)
        s.printVec(row);
    cout << endl;

    int output = s.minReorder(n, connections);
    cout << "Minumum flip to reach city 0: " << output << endl;
    return 0;
}

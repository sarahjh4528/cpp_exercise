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
Design: 
In a matrix, i+j is the same for same diagonal line, create a hash table to save the nums from bottom up.

Runtime 103 ms Beats 52.90%
Memory 101.16 MB Beats 49.45%

Time: O(n), space O(n)

Can improve space complexity by utilizing BFS,
From current cell, there are 2 possibilities, going down and moving right.

Moving right: If j < col - 1
On top of moving right, only allow first column to go down: If and only if j == 0 && i < row - 1
*/
#if 0
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        int maxIndex = 0;
        unordered_map<int, vector<int>> nmap;
        for (int i = n-1; i >= 0; i--) {
            int curCol = nums[i].size()-1;
            maxIndex = max(maxIndex, i+curCol);
            for (int j = 0; j <= curCol; j++) {
                nmap[i+j].push_back(nums[i][j]);
            }
        }
        vector<int> res;
        for (int i = 0; i <= maxIndex; i++)
            res.insert(res.end(), nmap[i].begin(), nmap[i].end());
        return res;
    }
#else
/*
Runtime 15 ms Beats 87.68%
Memory 69.54 MB Beats 81.47%
*/
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        
        queue<pair<int, int>> q;
        q.push(make_pair(0,0));
        vector<int> res;
        while (!q.empty()) {
            int qsize = q.size();
            for (int i = 0; i < qsize; i++) {
                auto [x, y] = q.front();
                q.pop();
                res.push_back(nums[x][y]);
                if (y == 0 && x < nums.size()-1)
                    q.push(make_pair(x+1, y));
                if (y < nums[x].size()-1)
                    q.push(make_pair(x, y+1));
            }
        }
        return res;
    }
#endif
};

int main()
{
#if 0
    vector<vector<int>> nums = {
        {1,2,3,4,5},
        {6,7},
        {8},
        {9,10,11},
        {12,13,14,15,16}
    };
    vector<vector<int>> nums = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    vector<vector<int>> nums = {
        {6},
        {8},
        {6,1,6,16}
    };
#else
    vector<vector<int>> nums = {
        {14,12,19,16,9},
        {13,14,15,8,11},
        {11,13,1}
    };
#endif
    Solution s;

    vector<int> output = s.findDiagonalOrder(nums);
    s.printVec(output);
    return 0;
}

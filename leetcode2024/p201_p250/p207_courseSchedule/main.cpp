#include<bits/stdc++.h>
#include<iostream>
#include<queue>

using namespace std;

class Solution {
public:
    void printVec(vector<int>& v) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (prerequisites.size() == 0)
            return true;

        unordered_map<int, vector<int>> cmap;
        vector<int> degree(numCourses, 0);
        vector<int> ans;

        for (auto pres : prerequisites) {
            cmap[pres[1]].push_back(pres[0]);   // Save all courses that needs pres[1]
            degree[pres[0]]++;                  // Courses to take before taking pres[0]
        }
        queue<int> q;   // Save courses can be taken
        for (int i = 0; i < numCourses; i++) {
            if (degree[i] == 0)
                q.push(i);
        }
        while (!q.empty()) {
            int take = q.front();
            q.pop();
            ans.push_back(take);
            for (auto toTake : cmap[take]) {
                degree[toTake]--;
                if (degree[toTake] == 0)
                    q.push(toTake);
            }
        }
        return ans.size() == numCourses;
    }
};

int main()
{
#if 0
    vector<vector<int>> prerequisites = {
        {1,0}
    };
    int numCourses = 2;
    vector<vector<int>> prerequisites = {
        {1,0}, {0,1}
    };
    int numCourses = 2;
#endif
    vector<vector<int>> prerequisites = {
        {1,0}, {0,1}
    };
    int numCourses = 2;

    Solution s;

    bool output = s.canFinish(numCourses, prerequisites);
    for (auto pre : prerequisites)
        s.printVec(pre);
    cout << "Can finish all courses: " << output << endl;
    return 0;
}

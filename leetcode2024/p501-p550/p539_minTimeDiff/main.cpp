#include<bits/stdc++.h>
#include<iostream>
#include<set>

using namespace std;

class Solution {
public:
    void printVec(vector<string>& v) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

/*
Runtime 2 ms Beats 77.81%
Memory 18.02 MB Beats 19.69%
*/
    int findMinDifference(vector<string>& timePoints) {
        // Time different between 0 - 23:59 in min : 0 - 24*60-1, in total 1024 elements
        // Read through entire vector, fill in time set.
        int upper = 24 * 60;            // Maximum 1440 elements
        if (timePoints.size() > upper)  // > 1440 elements => There must be same time elements
            return 0;
        set<int> mset;
        for (auto t : timePoints) {
            int curMinute = stoi(t.substr(0, 2))*60 + stoi(t.substr(3,2));
            if (mset.count(curMinute))
                return 0;
            mset.insert(curMinute);
        }
        int res = upper - *(prev(mset.end())) + *(mset.begin());
        for (auto it = next(mset.begin()); it != mset.end(); it++)
            res = min(res, (*it - *prev(it)));
        
        return res;



        int limit = 24 * 60;
        set<int> mset;
        for (auto t : timePoints) {
            int curtime = stoi(t.substr(0, 2))*60 + stoi(t.substr(3,2));
            if (mset.count(curtime))
                return 0;
            mset.insert(curtime);
        }
        int res = limit - *prev(mset.end()) + *(mset.begin());
        for (auto it = next(mset.begin()); it != mset.end(); it++) {
            res = min(res, (*it - *prev(it)));
        }
        return res; 
    }

};

int main()
{
    vector<vector<string>> vtime = {
        {"23:59","00:00"},
        {"00:00","23:59","00:00"}
    };
    Solution s;

    for (auto timePoints : vtime) {
        s.printVec(timePoints);
        int output = s.findMinDifference(timePoints);
        cout << "Min time diff: " << output << endl;
    }
    return 0;
}

#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        if (K == points.size())
            return points;

        map<int, vector<int>> distNPoints;
        for (int i = 0; i < points.size(); ++i) {
            int dist = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            if (distNPoints.find(dist) != distNPoints.end()) {
                distNPoints[dist].insert(distNPoints[dist].end(), {points[i][0], points[i][1]});
            } else {
                distNPoints[dist] = {points[i][0], points[i][1]};
            }
        }

        vector<vector<int>> res;
        int j = 0;
        map<int, vector<int>>::iterator it = distNPoints.begin();
        while (j < K) {
            vector<int>& curVec = it->second;
            if (curVec.size() == 2) {
                res.push_back(curVec);
                ++j;
            } else {
                int k = 0;
                while (k+1 < curVec.size()) {
                    res.push_back({curVec[k], curVec[k+1]});
                    ++j;
                    if (j == K)
                        break;
                    k += 2;
                }
            }
            ++it;
        }
        return res;
    }
};
int main()
{
#if 0
    vector<vector<int>> points = {
        {1, 3},
        {-2, 2}
    };
    int k = 1;
    vector<vector<int>> points = {
        {3, 3},
        {5, -1},
        {-2, 4},
    };
    int k = 2;
    vector<vector<int>> points = {
        {0, 1},
        {1, 0}
    };
    int k = 2;
    vector<vector<int>> points = {
        {1, 3},
        {-2, 2},
        {2, -2},
    };
    int k = 2;
#endif
    vector<vector<int>> points = {
        {0, 1},
        {1, 0}
    };
    int k = 2;

    Solution s;
    vector<vector<int>> closestPoints = s.kClosest(points, k);

    for (auto v : closestPoints) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}

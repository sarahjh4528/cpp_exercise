/*
Runtime 24 ms Beats 99.68%
Memory 66.35 MB Beats 78.44%
*/

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < points.size(); i++) {
            int x = points[i][0], y = points[i][1];
            int dist = x*x + y*y;
            pq.push(make_pair(dist, i));
            if (pq.size() > k)
                pq.pop();
        }
        vector<vector<int>> res;
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            res.push_back(points[cur.second]);
        }
        return res;
    }
};

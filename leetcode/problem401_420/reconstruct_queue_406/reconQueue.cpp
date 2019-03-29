#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(),
             [](pair<int, int>&p1, pair<int, int>&p2) {
                 return (p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second)); });
        vector<pair<int, int>> res;
        for (auto p : people) {
            res.insert(res.begin() + p.second, p);
        }

        return res;
    }
};

int main()
{
#if 0
    vector<pair<int, int>> people = {
        {7,0},
        {4,4},
        {7,1},
        {5,0},
        {6,1},
        {5,2}
    };
    vector<pair<int, int>> people = {
        {2,4},
        {3,4},
        {9,0},
        {0,6},
        {7,1},
        {6,0},
        {7,3},
        {2,5},
        {1,1},
        {8,0},
    };
#endif
    vector<pair<int, int>> people = {
        {2,4},
        {3,4},
        {9,0},
        {0,6},
        {7,1},
        {6,0},
        {7,3},
        {2,5},
        {1,1},
        {8,0},
    };
    Solution s;
    vector<pair<int, int>> reconVec = s.reconstructQueue(people); 
    for (auto p : reconVec)
        cout << p.first << " " << p.second << ",  " ;
    cout << endl;
    return 0;
}

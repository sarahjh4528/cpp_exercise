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
n == rooms.length
2 <= n <= 1000
0 <= rooms[i].length <= 1000
1 <= sum(rooms[i].length) <= 3000
0 <= rooms[i][j] < n
All the values of rooms[i] are unique.
*/
/*
Runtime 0 ms Beats 100.00%
Memory 14.59 MB Beats 59.42%
*/
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int size = rooms.size();
        vector<int> visited(size);
        stack<int> st;
        st.push(0);
        while (!st.empty()) {
            int i = st.top();
            visited[i] = 1;
            st.pop();
            for (auto r : rooms[i]) {
                if (!visited[r])
                    st.push(r);
            }
        }
        for (auto v : visited) {
            if (!v)
                return false;
        }
        return true;
        
    }
};

int main()
{
#if 0
    vector<vector<int>> rooms = { {1}, {2}, {3}, {} };
    vector<vector<int>> rooms = { {1,3}, {3,0,1}, {2}, {0} };
#endif
    vector<vector<int>> rooms = { {1,3}, {3,0,1}, {2}, {0} };
    Solution s;

    for (auto room : rooms)
        s.printVec(room);
    cout << endl;

    bool output = s.canVisitAllRooms(rooms);
    cout << "Can open all rooms: " << output << endl;

    return 0;
}

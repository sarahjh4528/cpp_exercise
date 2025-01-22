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

/*
2 <= asteroids.length <= 10^4
-1000 <= asteroids[i] <= 1000
asteroids[i] != 0
*/
/*
Runtime 0 ms Beats 100.00%
Memory 20.91 MB Beats 18.13%
*/
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for (auto n : asteroids) {
            if (n < 0) {
                while (!st.empty() && st.top() >= 0 && abs(n) > st.top())
                    st.pop();
                if (!st.empty() && st.top() >= abs(n)) {
                    if (st.top() == abs(n))
                        st.pop();
                    continue;
                }
                st.push(n);
            } else {
                st.push(n);
            }
        }
        vector<int> res;
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
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

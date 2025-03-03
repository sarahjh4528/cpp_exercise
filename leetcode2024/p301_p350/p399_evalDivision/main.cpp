#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
    unordered_map<string, vector<pair<string, double>>> qmap;
    double dfs(vector<string>& q, unordered_map<string, bool>& visited, string& cur, double curVal) {
        if (!qmap.count(cur))
            return -1;

        if (cur == q[1])
            return curVal;

        for (auto& [div, val] : qmap[cur]) {
            if (!visited.count(div)) {
                visited[div] = true;
                double res = dfs(q, visited, div, curVal*val);
                if (res != -1)
                    return res;
            }
        }
        return -1;
    }

public:
    void printVec(vector<string>& v) {
        for (auto i : v)
            cout << i << " ";
        cout << ", ";
    }

/*
1 <= equations.length <= 20
equations[i].length == 2
1 <= Ai.length, Bi.length <= 5
values.length == equations.length
0.0 < values[i] <= 20.0
1 <= queries.length <= 20
queries[i].length == 2
1 <= Cj.length, Dj.length <= 5
Ai, Bi, Cj, Dj consist of lower case English letters and digits.
*/

/*
Runtime 0 ms Beats 100.00%
Memory 12.14 MB Beats 21.50%

Time: O(M*N)
Space: O(M)
*/
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int size = equations.size();
        for (int i = 0; i < size; i++) {
            string& str1 = equations[i][0];
            string& str2 = equations[i][1];
            qmap[str1].push_back(make_pair(str2, values[i]));
            qmap[str2].push_back(make_pair(str1, 1.0/values[i]));
        }
        int qsize = queries.size();
        vector<double> res(qsize);
        for (int i = 0; i < qsize; i++) {
            vector<string>& q = queries[i];
            if (!qmap.count(q[0]) || !qmap.count(q[1]))
                res[i] = -1.0;
            else {
                unordered_map<string, bool> visited;
                visited[q[0]] = true;
                res[i] = dfs(q, visited, q[0], 1);
            }
        }
        return res;
    }
};

int main()
{
#if 0
    vector<vector<string>> equations = { {"a","b"}, {"b","c"} };
    vector<double> values = {2.0, 3.0};
    vector<vector<string>> queries = { {"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"} };

    vector<vector<string>> equations = { {"a","b"}, {"b","c"}, {"bc","cd"} };
    vector<double> values = {1.5, 2.5, 5.0};
    vector<vector<string>> queries = { {"a","c"},{"c","b"},{"bc","cd"},{"cd","bc"} };
#endif
    vector<vector<string>> equations = { {"a","b"}, {"b","c"}, {"bc","cd"} };
    vector<double> values = {1.5, 2.5, 5.0};
    vector<vector<string>> queries = { {"a","c"},{"c","b"},{"bc","cd"},{"cd","bc"} };
    Solution s;

    vector<double> output = s.calcEquation(equations, values, queries);
    for (int i = 0; i < queries.size(); i++)
        cout << queries[i][0] << " / " << queries[i][1] << " = " << output[i] << endl;
    
    return 0;
}

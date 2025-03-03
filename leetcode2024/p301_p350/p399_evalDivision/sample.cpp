#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
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
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
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

#include<iostream>
#include<stack>
#include<vector>
#include<utility>

using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        if (T.empty())
            return {};

        vector<int> days(T.size(), 0);
        stack<pair<int, int>> records;
        for (int i = T.size() - 1; i >= 0; --i) {
            while (!records.empty() && records.top().first <= T[i])
                records.pop();

            if (!records.empty())
                days[i] = records.top().second - i;

#if 0
// 212 ms, less than 96.73% mem
            records.push({T[i], i});
#else
// 200 ms, less than 100% mem
            if (records.empty() || records.top().first != T[i])
                records.push({T[i], i});
            else
                records.top().second = i;
#endif
        }
        return days;
    }
};

int main()
{
#if 0
    vector<int> temps = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> temps = {89,62,70,58,47,47,46,76,100,70};
#endif
    vector<int> temps = {89,62,70,58,47,47,46,76,100,70};

    Solution s;
    vector<int> days = s.dailyTemperatures(temps);
    for (auto d : days)
        cout << d << " ";
    cout << endl;

    return 0;
}

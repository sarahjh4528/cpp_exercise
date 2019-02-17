#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    void printRow(vector<int> &v) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0)
            return {1};
        if (rowIndex == 1)
            return {1,1};
        vector<int> prev = {1, 1};
        vector<int> ret = {1, 1};

        for (int i = 2; i <= rowIndex; ++i) {
            ret.insert(ret.begin() + 1, 0);
            for (int j = 1; j < ret.size() - 1; ++j) {
                ret[j] = prev[j] + prev[j-1];
            }
            prev.insert(prev.begin() + 1, 0);
            copy(ret.begin(), ret.end(), prev.begin());
        }
        return ret;
    }
};

int main()
{
    Solution s;
    int row = 4;

    vector<int> rowVec = s.getRow(row);
    s.printRow(rowVec);
    return 0;
}

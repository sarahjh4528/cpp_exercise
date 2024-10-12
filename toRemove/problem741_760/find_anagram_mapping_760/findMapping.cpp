#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

class Solution
{
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
#if 0
        unordered_map<int, queue<int>> mapDict;
        for (int i = 0; i < B.size(); ++i) {
            mapDict[B[i]].push(i);
        }
        vector<int> ret;
        for (int j = 0; j < A.size(); ++j) {
            unordered_map<int, queue<int>>::iterator it = mapDict.find(A[j]);
            if (it != mapDict.end()) {
                ret.push_back(mapDict[A[j]].front());
                mapDict[A[j]].pop();
            }
        }
        return ret;
#else
// Better version. Both 100%
        unordered_map<int, int> bMap;
        for (int i = 0; i < B.size(); ++i) {
            bMap[B[i]] = i;
        }
        vector<int> ret(A.size(), 0);
        int j = 0;
        for (auto a : A) {
            ret[j++] = bMap[a];
        }
        return ret;
#endif
    }
};
int main()
{
#if 0
    vector<int> A = {12, 28, 46, 32, 50};
    vector<int> B = {50, 12, 32, 46, 28};
#endif
    vector<int> A = {12, 28, 46, 32, 50, 32, 6};
    vector<int> B = {50, 12, 32, 46, 28, 6, 32};

    Solution s;
    vector<int> mapping = s.anagramMappings(A, B);
    for (auto i : mapping)
        cout << i << " ";
    cout << endl;
    return 0;
}

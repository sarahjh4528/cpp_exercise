#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    void printVec(vector<int>& v) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

/*
1 <= costs.length <= 10^5 
1 <= costs[i] <= 10^5
1 <= k, candidates <= costs.length
*/
/*
Runtime 40 ms Beats 59.20%
Memory 76.89 MB Beats 50.77%
*/
#if 1
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<int>> pq1, pq2;
        int left, right, size = costs.size();
        for (left = 0; left < candidates; left++)
            pq1.push(costs[left]);
        for (right = size-1; right >= size-candidates && right >= left; right--)
            pq2.push(costs[right]);
        long long res = 0;
        while (!pq1.empty() && !pq2.empty() && k > 0) {
            if (pq1.top() <= pq2.top()) {
                res += pq1.top();
                pq1.pop(); 
                if (left <= right)
                    pq1.push(costs[left++]);
            } else {
                res += pq2.top();
                pq2.pop();
                if (left <= right)
                    pq2.push(costs[right--]);
            }
            k--;
        }
        while (k > 0) {
            if (pq1.empty()) {
                res += pq2.top();
                pq2.pop();
            } else {
                res += pq1.top();
                pq1.pop();
            }
            k--;
        }
        return res;
    }
#else
/*
Runtime 41 ms Beats 56.46%
Memory 76.76 MB Beats 70.84%
*/
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<int>> pq1, pq2;
        int left, right, size = costs.size();
        for (left = 0; left < candidates; left++)
            pq1.push(costs[left]);
        for (right = size-1; right >= size-candidates && left <= right; right--)
            pq2.push(costs[right]);
        long long res = 0;
        while (k > 0) {
            if (!pq1.empty() && !pq2.empty()) {
                if (pq1.top() <= pq2.top()) {
                    res += pq1.top();
                    pq1.pop();
                    if (left <= right)
                        pq1.push(costs[left++]);
                } else {
                    res += pq2.top();
                    pq2.pop();
                    if (left <= right)
                        pq2.push(costs[right--]);
                }
            } else {
                if (pq1.empty()) {
                    res += pq2.top();
                    pq2.pop();
                } else {
                    res += pq1.top();
                    pq1.pop();
                }
            }
            k--;
        }
        return res;
    }
#endif
};

int main()
{
    vector<vector<int>> vcosts = {
        {17,12,10,2,7,2,11,20,8},
        {1,2,4,1}
    };
    vector<int> vk = {3,3};
    vector<int> vcandidates = {4,3};
    Solution s;

    for (int i = 0; i < vk.size(); i++) {
        s.printVec(vcosts[i]);
        long long output = s.totalCost(vcosts[i], vk[i], vcandidates[i]);
        cout << "Total cost hire " << vk[i] << " workers: " << output << endl;
    }

    return 0;
}

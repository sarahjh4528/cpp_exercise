

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
#if 0
/*
Runtime 0 ms Beats 100.00%
Memory 12.56 MB Beats 14.39%
*/
    void sumList(NestedInteger& ni, int& sum, int depth) {
        if (ni.isInteger()) {
            sum += ni.getInteger() * depth;
            return;
        }
        for (auto nl : ni.getList()) {
            sumList(nl, sum, depth+1);
        }
    }
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        int res = 0;
        for (auto nl : nestedList) {
            sumList(nl, res, 1);
        }
        return res;
    }
#else
/*
Runtime 0 ms Beats 100.00%
Memory 12.62 MB Beats 9.23%
*/
    void solve(vector<NestedInteger>& nl, int& res, int depth) {
        for (auto ni : nl) {
            if (ni.isInteger()) {
                res += ni.getInteger() * depth;
            } else {
                solve(ni.getList(), res, depth+1);
            }
        }
    }
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        int res = 0;
        solve(nestedList, res, 1);
        return res;
    }
#endif
};

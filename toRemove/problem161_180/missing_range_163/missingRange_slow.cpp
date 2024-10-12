/*
 * Given a sorted integer array nums, where the range of elements are in the
 * inclusive range [lower, upper], return its missing ranges.
 * 
 * Example:
 * Input: nums = [0, 1, 3, 50, 75], lower = 0 and upper = 99,
 * Output: ["2", "4->49", "51->74", "76->99"]
 */
#include<iostream>
#include<vector>
#include<set>

using namespace std;

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        if (nums.empty()) {
            string rstr = (lower == upper)? to_string(lower) :
                          to_string(lower) + "->" + to_string(upper);
            return {rstr};
        }

        long long cur = lower;
        vector<string> res;
        set<int> numSet(nums.begin(), nums.end());
        for (auto i : numSet) {
            int start = cur, end = cur;
            string rangeStr = "";
            if (i > cur ) {
                start = cur;
                end = i - 1;
                rangeStr = (start == end)? to_string(start) :
                                           to_string(start) + "->" + to_string(end);
                res.push_back(rangeStr);
                cur = i;
            }
            ++cur;
        }
        if (cur < upper) {
            string rStr = to_string(cur) + "->" + to_string(upper);
            res.push_back(rStr);
        } else if (cur == upper) {
            res.push_back(to_string(upper));
        }
        return res;
    }
};

int main()
{
    Solution s;
#if 0
    vector<int> nums = {0, 1, 3, 50, 75};
    int lower = 0, upper = 99;

    vector<int> nums = {-2147483648,-2147483648,0,2147483647,2147483647};
    int lower = -2147483648, upper = 2147483647;
#endif
    vector<int> nums = {-2147483648,-2147483648,0,2147483647,2147483647};
    int lower = -2147483648, upper = 2147483647;

    vector<string> output = s.findMissingRanges(nums, lower, upper);

    for (auto str : output)
        cout << str << endl;
    return 0;
}

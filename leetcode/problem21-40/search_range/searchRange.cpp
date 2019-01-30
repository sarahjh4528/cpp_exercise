#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;

class Solution 
{
public:
    void printList(vector<int> &iList) {
        for (auto i : iList)
            cout << i << " ";
        cout << endl;
    }

    int findStart(vector<int>& nums, int target, int start, int end) {
        // To enter this function, nums[end] == target
        if (start == end) {
            if (nums[start] == target)
                return start;
            else
                return -1;
        }

        cout << "findStart start " << start << ", end " << end << endl;
        int midpoint = (end - start) / 2 + start;
        int start_pos;
        if (target == nums[midpoint]) {
            if (midpoint > start && target == nums[midpoint-1])
                start_pos = findStart(nums, target, start, midpoint - 1);
            else
                return midpoint;
        } else  {    // target > nums[midpoint]
            // target won't be < nums[midpoint]
            if (midpoint < end)
                start_pos = findStart(nums, target, midpoint+1, end);
            else
                return end;
        }
        return start_pos;
    }

    int findEnd(vector<int>& nums, int target, int start, int end) {
        if (start == end) {
            cout << "start " << start << ", end " << end << endl;
            if (nums[start] == target)
                return start;
            else
                return -1;
        }

        cout << "findEnd start " << start << ", end " << end << endl;
        int midpoint = (end - start) / 2 + start;
        int end_pos;
        if (target == nums[midpoint]) {
            if (midpoint < end && target == nums[midpoint + 1])
                end_pos = findEnd(nums, target, midpoint + 1, end);
            else
                end_pos = midpoint;
        } else {
            if (midpoint > start)
                end_pos = findEnd(nums, target, start, midpoint - 1);
            else
                end_pos = start;
        }
        return end_pos;
    }

    vector<int> searchRangeWithIndex(vector<int>& nums, int target, int start, int end) {
        if (start == end) {
            if (nums[start] == target)
                return {start, start};
            else
                return {-1, -1};
        }

        int midpoint = (end - start) / 2 + start;
        int start_pos, end_pos; 
        if (target == nums[midpoint]) {
            start_pos = findStart(nums, target, start, midpoint);
            end_pos = findEnd(nums, target, midpoint, end);
        } else if (target > nums[midpoint]) {
            return searchRangeWithIndex(nums, target, midpoint + 1, end);
        } else {
            if (midpoint - 1 < start)
                return {-1, -1};

            return searchRangeWithIndex(nums, target, start, midpoint - 1);
        }
        return {start_pos, end_pos};
            
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty())
            return {-1, -1};

        return searchRangeWithIndex(nums, target, 0, (nums.size() - 1));
    }
};

int main()
{
#if 0
    vector<int> iList = {5,7,7,8,8,10};
    int target = 8;
    vector<int> iList = {5,7,7,8,8,10};
    int target = 6;
    vector<int> iList = {2,2};
    int target = 2;
    vector<int> iList = {1,2,3,3,3,3,4,5,9};
    int target = 3;
    vector<int> iList = {1,2,3,3,3,3,4,5,9};
    int target = 3;
#endif
    vector<int> iList = {5,7,7,8,8,10};
    int target = 8;

    Solution s;
    vector<int> output = s.searchRange(iList, target);

    s.printList(iList);
    s.printList(output);

    return 0;
}

#include<unordered_map>
#include<vector>
#include<iostream>

using namespace std;

void printVector(vector<int>& indices) {
    for (auto i : indices)
        cout << i << " ";
    cout << endl;
}

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> myTable;
    for (int i = 0; i < nums.size(); i++) {
        if (myTable.find(target - nums[i]) != myTable.end())
            return {myTable[target-nums[i]], i};
        else
            myTable[nums[i]] = i;
    }
    return {};
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    vector<int> ret = twoSum(nums, 9);

    printVector(ret);
    return 0;
}

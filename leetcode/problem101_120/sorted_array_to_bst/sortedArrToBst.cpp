#include<iostream>
#include<vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode* buildTree(vector<int>& nums, int start, int stop) {
        if (start > stop)
            return NULL;
        else if (start == stop)
            return (new TreeNode(nums[start]));

        int mid = (stop - start) / 2 + start;
        TreeNode *top = new TreeNode(nums[mid]);
        top->left = buildTree(nums, start, mid - 1);
        top->right = buildTree(nums, mid + 1, stop);
        return top;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty())
            return NULL;

        int mid = nums.size() / 2;
        TreeNode *top = new TreeNode(nums[mid]);
        top->left = buildTree(nums, 0, mid - 1);
        top->right = buildTree(nums, mid + 1, nums.size() - 1);
        return top;
    }
};

int main()
{
    vector<int> inArr = {-10,-3,0,5,9};
    Solution s;
    TreeNode *top = s.sortedArrayToBST(inArr);
    cout << top->val << endl;
    return 0;
}

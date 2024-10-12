#include<iostream>
#include<vector>

using namespace std;

class Solution { 
public:
    void printVector(const vector<int>& v) {
        for (auto n: v)
            cout << n << " ";
        cout << endl;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        int mLen = len1 + len2;
        int mIndex = 0, n1 = 0, n2 = 0;
        bool isOdd = false;
        if (mLen % 2) {
            // Odd case, find middle value
            mIndex = (mLen - 1) / 2;
            isOdd = true;
        } else {
            // Even case, find middle 2 values, average, need another var
            mIndex = mLen / 2;
        }
        int value = 0, value2 = 0;
        for (int i = 0; i <= mIndex; ++i) {
            if (n1 < len1 && n2 < len2) {
                if (nums1[n1] <= nums2[n2]) {
                    value = nums1[n1];
                    ++n1;
                } else {
                    value = nums2[n2];
                    ++n2;
                }
            } else if (n1 < len1) {
                value = nums1[n1];
                ++n1;
            } else {
                value = nums2[n2];
                ++n2;
            }
            if (i == mIndex - 1)
                value2 = value;
        }
        if (isOdd)
            return double(value);
        else
            return (double(value) + double(value2)) / 2;
    }
};

int main()
{
    vector<vector<int>> vNums1 = {
        {1, 4, 6, 19, 39, 50},
        {},
        {1, 3},
        {1, 2},
    };
    vector<vector<int>> vNums2 = {
        {},
        {2, 14, 36, 48, 80, 81, 82, 95},
        {2},
        {3, 4},
    };
//    vector<int> vc2 = {2, 14, 36, 48, 95};
    Solution s;
    for (int i = 0; i < vNums1.size(); ++i) {
        double medianValue = s.findMedianSortedArrays(vNums1[i], vNums2[i]);
        s.printVector(vNums1[i]);
        s.printVector(vNums2[i]);
        cout << "Median: " << medianValue << endl;
    }

    return 0;
}

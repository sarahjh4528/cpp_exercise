#include<iostream>
#include<vector>

using namespace std;

void printVector(const vector<int>& v)
{
    for (auto elem: v) {
        cout << elem << " ";
    }
    cout << endl;
}

double findMedian(vector<int>& nums) {
    double medianValue = 0;
    int len = nums.size();
    cout << "merged array length: " << len << endl;
    if (len % 2) {
        medianValue = nums[(len - 1) / 2];
    } else {
        int middle1Index = len / 2;
        int middle2Index = middle1Index - 1;
        medianValue = (nums[middle1Index] + nums[middle2Index]) / 2.0;
    }
    return medianValue;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int nums1Len = nums1.size();
    int nums2Len = nums2.size();

    if (nums1Len == 0) {
        return findMedian(nums2);
    }

    if (nums2Len == 0) {
        return findMedian(nums1);
    }
   
    vector<int> mergedV;
    int index1 = 0, index2 = 0;
    printVector(nums1);
    printVector(nums2);
    cout << "nums1 length: " << nums1Len << ", nums2 length: " << nums2Len << endl;

    while (1) {
        if (nums1[index1] <= nums2[index2]) {
            mergedV.push_back(nums1[index1]);
            index1 = (index1 < nums1Len)? ++index1 : nums1Len;

        }
        if (nums2[index2] <= nums1[index1]) {
            mergedV.push_back(nums2[index2]);
            index2 = (index2 < nums2Len)? ++index2 : nums2Len;
        }
        if (index1 == nums1Len) {
            // Reached end of nums1, append all rest of nums2 to mergedV
            for (int i = index2; index2 != nums2Len; ++index2)
                mergedV.push_back(nums2[index2]);
            break;
        } else if (index2 == nums2Len) {
            // Reached end of nums2, append all rest of nums2 to mergedV
            for (int i = index1; index1 != nums1Len; ++index1)
                mergedV.push_back(nums1[index1]);
            break;
        }
    }
    printVector(mergedV);
    return findMedian(mergedV);

}

int main()
{
    vector<int> vc1 = {1, 4, 6, 19, 39, 50};
//    vector<int> vc1 = {};
//    vector<int> vc2 = {2, 14, 36, 48, 95};
    vector<int> vc2 = {2, 14, 36, 48, 80, 81, 82, 95};
//    vector<int> vc2 = {};

    double medianValue = findMedianSortedArrays(vc1, vc2);
    cout << "Median: " << medianValue << endl;
    return 0;
}

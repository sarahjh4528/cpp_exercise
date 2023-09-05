#include<iostream>
#include<vector>

using namespace std;

int arrTemp[10] = {0};

void printVec(vector<int>& v)
{
    for (auto i : v)
        cout << i << " ";
    cout << endl;
}

vector<int> mergeVec(vector<int>& v1, vector<int>& v2)
{
    vector<int> ret;

    int v1Len = v1.size(), v2Len = v2.size();
    int i1 = 0, i2 = 0;
    while (i1 < v1Len && i2 < v2Len) {
        if (v1[i1] < v2[i2]) {
            ret.push_back(v1[i1]);
            i1++;
        } else {
            ret.push_back(v2[i2]);
            i2++;
        }
    }
    if (i1 < v1Len)
        ret.insert(ret.end(), v1.begin() + i1, v1.end());
    else
        ret.insert(ret.end(), v2.begin() + i2, v2.end());

    return ret;
}

vector<int> mergeSort(int low, int high, vector<int>& nums)
{
    if (low >= high)
        return {nums[high]};

    int mid = (low + high) / 2;
    vector<int> left = mergeSort(low, mid, nums);
    vector<int> right = mergeSort(mid+1, high, nums);
    return mergeVec(left, right);
}

int main() {
    vector<int> vec = {45, 2, 33, 44, 28, 19, 220, 99, 49, 50};
    cout << "Before sort: " << endl;
    printVec(vec);
    vector<int> sortedNums = mergeSort(0, vec.size() - 1, vec);
    cout << "after sort: " << endl;
    printVec(sortedNums);
    return 0;
}

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

void mergeArray(const vector<int>& v1, const vector<int>& v2)
{
    vector<int> mergedV;
    int index1 = 0, index2 = 0;
    int v1Len = v1.size();
    int v2Len = v2.size();

    printVector(v1);
    printVector(v2);
    cout << "v1 length: " << v1Len << ", v2 length: " << v2Len << endl;

    while (1) {
        if (v1[index1] <= v2[index2]) {
            mergedV.push_back(v1[index1]);
            index1 = (index1 < v1Len)? ++index1 : v1Len;
            
        }
        if (v2[index2] <= v1[index1]) {
            mergedV.push_back(v2[index2]);
            index2 = (index2 < v2Len)? ++index2 : v2Len;
        }
        if (index1 == v1Len) {
            // Reached end of v1, append all rest of v2 to mergedV
            for (int i = index2; index2 != v2Len; ++index2)
                mergedV.push_back(v2[index2]);
            break;
        } else if (index2 == v2Len) {
            // Reached end of v2, append all rest of v2 to mergedV
            for (int i = index1; index1 != v1Len; ++index1)
                mergedV.push_back(v1[index1]);
            break;
        }
    }
    printVector(mergedV);
}

int main()
{
    vector<int> vc1 = {1, 4, 6, 19, 39, 50};
    vector<int> vc2 = {2, 14, 36, 48, 95};

    mergeArray(vc1, vc2);
    return 0;
}


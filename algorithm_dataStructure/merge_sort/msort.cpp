#include<iostream>
#include<iterator>

using std::cout;
using std::endl;

int arr[10] = {45, 2, 33, 44, 28, 19, 220, 99, 49, 50};
int arrTemp[10] = {0};

void printArr(int *arr, int aLen)
{
    for (int i = 0; i != aLen; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void mergeArray(int low, int mid, int high)
{
    int index1 = low, index2 = mid + 1;
    int indexTemp = low;

    while (index1 <= mid && index2 <= high) {
        if (arr[index1] < arr[index2]) {
            arrTemp[indexTemp] = arr[index1];
            ++index1;
        } else {
            arrTemp[indexTemp] = arr[index2];
            ++index2;
        }
        ++indexTemp;
    }
    while (index1 <= mid) {
        arrTemp[indexTemp] = arr[index1];
        ++index1;
        ++indexTemp;
    }
    while (index2 <= high) {
        arrTemp[indexTemp] = arr[index2];
        ++index2;
        ++indexTemp;
    }

    for (int i = low; i <= high; ++i) {
        arr[i] = arrTemp[i];
    }
}

void mSort(int low, int high)
{
    if (low < high) {
        int mid = (high - low) / 2 + low;
        mSort(low, mid);
        mSort(mid+1, high);
        mergeArray(low, mid, high);
    }
}

int main() {
    cout << "Before sort: " << endl;
    printArr(arr, 10);
    mSort(0, 9);
    cout << "after sort: " << endl;
    printArr(arr, 10);
    return 0;
}

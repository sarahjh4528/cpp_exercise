#include<iostream>
using std::cout;
using std::endl;

void printArray(int *a, int aLen)
{
    if (!a || aLen == 0)
        return;

    for (int i = 0; i < aLen; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void sSort(int *a, int aLen)
{
    if (!a || aLen <= 0)
        return;

    for (int i = 0; i < aLen; ++i) {
        int minNum = a[i];
        int minIndex = i;
        for (int j = i + 1; j < aLen; ++j) {
            if (a[j] < minNum) {
                minNum = a[j];
                minIndex = j;
            }
        }
        if (i != minIndex)
            swap(a[i], a[minIndex]);
    }
}

int main()
{
    int arr[10] = {45, 2, 33, 44, 28, 19, 220, 99, 49, 50};

    cout << "Before" << endl;
    printArray(arr, 10);

    sSort(arr, 10);
    cout << "After" << endl;
    printArray(arr, 10);
    return 0;
}

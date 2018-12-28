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

void iSort(int *a, int arrLen)
{
    if (!a || arrLen <= 1 )
        return;

    int toSort = 1;

    for (int i = 1; i != arrLen; ++i) {
        for (int j = toSort; j > 0; --j) {
            if (a[j] < a[j-1])
                swap(a[j], a[j-1]);
            else
                break;
        }
        ++toSort;
    }
}

int main()
{
    int arr[10] = {45, 2, 33, 44, 28, 19, 220, 99, 49, 50};

    cout << "Before" << endl;
    printArray(arr, 10);

    iSort(arr, 10);
    cout << "After" << endl;
    printArray(arr, 10);
    return 0;
}

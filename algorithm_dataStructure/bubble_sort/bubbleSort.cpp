#include<iostream>
using std::cout;
using std::endl;

#if 0
// This also works
void printArray(int (&a)[10])
{
    for (auto i : a) {
        cout << i << " ";
    }
    cout << endl;
}
#endif

void printArray(int *a, int aLen)
{
    if (!a || aLen == 0)
        return;
//    cout << "sizeof(*a): " << sizeof(*a) << endl;
//    cout << "sizeof(a): " << sizeof(a) << endl;

    for (int i = 0; i < aLen; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void bSort(int *a, int aLen)
{
    if (!a || aLen == 0)
        return;
    int endIndx = aLen - 1;

    for (int i = 0; i < aLen; ++i) {
        bool swapped = false;
        for (int j = 0; j < endIndx; ++j) {
            if (a[j] > a[j+1]) {
                swap(a[j], a[j+1]);
                swapped = true;
            }
        }
        if (!swapped)    //sort done
            break;

        --endIndx;
    }
}

int main()
{
    int arr[10] = {45, 2, 33, 44, 28, 19, 220, 99, 49, 50};

    cout << "Before" << endl;
    printArray(arr, 10);

    bSort(arr, 10);
    cout << "After" << endl;
    printArray(arr, 10);
    return 0;
}

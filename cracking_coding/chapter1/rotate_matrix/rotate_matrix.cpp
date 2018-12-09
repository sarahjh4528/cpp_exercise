#include<iostream>

using namespace std;

template <typename T, size_t N, size_t M>
void printMatrix(T (&m)[N][M])
{
    for (int i = 0; i != N; ++i) {
        for (int j = 0; j != M; ++j)
            cout << m[i][j] << " ";
        cout << endl;
    }
}

template <typename T, size_t N, size_t M>
void rotateMatrix(T (&m)[N][M])
{
    if (N == 0 || M == 0)
        return;
    for (int i = 0; i != N / 2; ++i) {
        for (int j = i; j != N - i - 1; ++j) {
            T temp = m[i][j];
            m[i][j] = m[N-1-j][i];
            m[N-1-j][i] = m[N-1-i][N-1-j];
            m[N-1-i][N-1-j] = m[j][N-1-i];
            m[j][N-1-i] = temp;
        }
    }
}

int main()
{
/*
    int m[4][4] = {
        1,2,3,4,
        5,6,7,8,
        9,10,11,12,
        13,14,15,16
    };
    int m[3][3] = {
        1,2,3,
        5,6,7,
        9,10,11
    };
    */
    int m[7][7] = {
        1,2,3,4,5,6,7,
        5,6,7,8,5,6,7,
        9,10,11,12,6,7,8,
        13,14,15,166,7,8,8,
        1,2,3,4,5,6,7,
        2,3,4,2,3,4,5,
        1,1,1,1,1,1,1
    };

    cout << "Before rotation: " << endl;
    printMatrix(m);
    rotateMatrix(m);
    cout << endl << "After rotation: " << endl;
    printMatrix(m);
    return 0;
}

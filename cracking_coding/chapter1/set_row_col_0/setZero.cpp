#include<iostream>
#include<unordered_set>

using namespace std;

template <typename T, size_t N, size_t M>
void printMatrix(T (&m)[N][M])
{
    for (int i = 0; i != N; ++i) {
        for (int j = 0 ; j != M; ++j) {
            cout << m[i][j] << ", ";
        }
        cout << endl;
    }
    cout << endl;
}

template <typename T, size_t N, size_t M>
void setZero(T (&m)[N][M])
{
    unordered_set<int> row_to_replace, col_to_replace;
    for (int i = 0; i != N; ++i) {
        for (int j = 0; j != M; ++j) {
            if (m[i][j] == 0) {
                row_to_replace.insert(i);
                col_to_replace.insert(j);
            }
        }
    }

    // Set rows and cols to 0.
    for (int i = 0; i != N; ++i) {
        unordered_set<int>::const_iterator found = row_to_replace.find(i);
        if (found != row_to_replace.end()) {
            for (int j = 0; j != M; ++j)
                m[i][j] = 0;
        }
        unordered_set<int>::iterator it;
        for (it = col_to_replace.begin(); it != col_to_replace.end(); ++it)
            m[i][*it] = 0;
    }
}

int main()
{
#if 0
    int inMatrix[4][5] = {
        1, 3, 5, 7, 0,
        2, 4, 6, 8, 10,
        11,11,11,11,11,
        22,22,22,22,22
    };
#endif
    int inMatrix[5][5] = {
        1, 3, 5, 7, 4,
        2, 4, 6, 8, 10,
        11,11,0,11,11,
        22,22,22,22,22,
        22,22,22,22,22
    };

    printMatrix(inMatrix);
    setZero(inMatrix);
    cout << "result: " << endl;
    printMatrix(inMatrix);
    return 0;
}

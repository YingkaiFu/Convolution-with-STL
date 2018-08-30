#include <iostream>
#include "cuda.h"
#include "matrix_with_stl.h"
int main() {
    cuda();
    int M1[2][4] = {1, 2, 1, 0, 0, -1, 1, 0};
    int M2[4][3] = {1, -1, 1, 0, 1, 2, 0, 1, 0, 1, 0, 1};
    matrix(M1, M2);
    int M3[6][6] = {1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1,
                    0, 0, 1};
    int M4[3][3] = {1, -1, 1, 0, 1, 0, 1, -1, 1};
    conv(M3, M4, 3, 3);
    vector<vector<int>> newOne(2, vector<int>(4, 0));
    for (int i = 0; i < newOne.size(); ++i) {
        for (int j = 0; j < newOne[0].size(); ++j) {
            newOne[i][j] = M1[i][j];
        }
    }
    vector<vector<int>> ewOne(4, vector<int>(3, 0));
    for (int i = 0; i < ewOne.size(); ++i) {
        for (int j = 0; j < ewOne[0].size(); ++j) {
            ewOne[i][j] = M2[i][j];
        }
    }
    vector<vector<int>> O(newOne.size(), vector<int>(ewOne[0].size(), 0));
    O = matrix(newOne, ewOne);

    vector<vector<int>> M_M3(6, vector<int>(6, 0));
    for (int i = 0; i < M_M3.size(); ++i) {
        for (int j = 0; j < M_M3[0].size(); ++j) {
            M_M3[i][j] = M3[i][j];
        }
    }
    vector<vector<int>> M_M4(3, vector<int>(3, 0));
    for (int i = 0; i < M_M4.size(); ++i) {
        for (int j = 0; j < M_M4[0].size(); ++j) {
            M_M4[i][j] = M4[i][j];
        }
    }
    vector<vector<int>> O1(2, vector<int>(2, 0));
    O1 = conv(M_M3, M_M4, 3, 0);
    for (int k = 0; k < O1.size(); ++k) {
        for (int i = 0; i < O1[0].size(); ++i) {
            cout << O1[k][i] << " ";
        }
        cout << endl;
    }
    return 0;
}
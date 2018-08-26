//
// Created by yingkai on 18-8-26.
//
#include "iostream"
#include "cuda.h"

using namespace std;
const int A = 2, B = 4, C = 3;

void matrix(int M1[A][B], int M2[B][C]) {
    int O[A][C] = {0};
    for (int i = 0; i < A; ++i) {
        for (int j = 0; j < C; ++j) {
            int sum = 0;
            for (int k = 0; k < B; ++k) {
                sum += M1[i][k] * M2[k][j];
            }
            O[i][j] = sum;
        }
    }
}

void conv(int M1[6][6], int M2[3][3], int stride, int Ksize) {
    const int FS = 6;
    int W = ((6 - Ksize) / stride + 1) * ((6 - Ksize) / stride + 1);
    int H = Ksize * Ksize;
    int Out[H][W] = {0};
    for (int k = 0; k < H; ++k) {
        for (int i = 0; i < W; ++i) {
            Out[k][i] = M1[k / 3 + (i / 2) * 3][k % 3 + (i % 2) * 3];
        }
    }
    //图像变换后的矩阵Out
    cout << "Out" << endl;
    for (int k = 0; k < H; ++k) {
        for (int i = 0; i < W; ++i) {
            cout << Out[k][i] << " ";
        }
        cout << endl;
    }
    //核变换后的矩阵Kernel
    int Kernel[1][H] = {0};
    for (int j = 0; j < H; ++j) {
        Kernel[0][j] = M2[j / 3][j % 3];
    }
    //矩阵相乘
    int O[1][4] = {0};
    for (int i = 0; i < 1; ++i) {
        for (int j = 0; j < 4; ++j) {
            int sum = 0;
            for (int k = 0; k < 9; ++k) {
                sum += Kernel[i][k] * Out[k][j];
            }
            O[i][j] = sum;
            cout << sum << endl;
        }
    }
    cout << endl;
    //重新组合为图像
    int out[(6 - Ksize) / stride + 1][(6 - Ksize) / stride + 1] = {0};
    for (int m = 0; m < 4; ++m) {
        out[m / 2][m % 2] = O[0][m];
    }
    for (int n = 0; n < (6 - Ksize) / stride + 1; ++n) {
        for (int i = 0; i < (6 - Ksize) / stride + 1; ++i) {
            cout << out[n][i] << " ";
        }
        cout << endl;
    }
}

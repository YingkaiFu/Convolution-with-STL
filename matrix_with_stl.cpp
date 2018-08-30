//
// Created by yingkai on 18-8-29.
//

#include "matrix_with_stl.h"

vector<vector<int>> matrix(vector<vector<int>> &M1, vector<vector<int>> &M2) {
    vector<vector<int>> Output(M1.size(), vector<int>(M2[0].size(), 0));
    for (int i = 0; i < M1.size(); ++i) {
        for (int j = 0; j < M2[0].size(); ++j) {
            Output[i][j] = 0;
            for (int k = 0; k < M1[0].size(); ++k) {
                Output[i][j] += M1[i][k] * M2[k][j];
            }
        }
    }
//    for (int i = 0; i < M1.size(); ++i) {
//        for (int j = 0; j < M2[0].size(); ++j) {
//
//            cout << O[i][j] << " ";
//
//        }
//        cout << endl;
//    }
    return Output;
}

vector<vector<int>> conv(vector<vector<int>> &M1, vector<vector<int>> &M2, int stride, int padding) {
    cout << "STL conv";
    assert(M1.size() == M1[0].size() && M2.size() == M2[0].size() && stride > 0);
    int ImageSize = M1.size();
    int Out_Size = (ImageSize - M2.size()) / stride + 1;
    int M_W = Out_Size * Out_Size;
    int M_H = M2.size() * M2.size();
    vector<vector<int>> M(M_H, vector<int>(M_W, 0));
    for (int i = 0; i < M_H; ++i) {
        for (int j = 0; j < M_W; ++j) {
            M[i][j] = M1[i / M2.size() + (j / Out_Size) * stride][i % M2.size() + (j % Out_Size) * stride];
        }
    }
    cout << endl;
    vector<vector<int>> Kernel(1, vector<int>(M_H, 0));
    for (int j = 0; j < M_H; ++j) {
        Kernel[0][j] = M2[j / M2.size()][j % M2.size()];
    }

//    for (int i = 0; i < M_H; ++i) {
//        for (int j = 0; j < M_W; ++j) {
//            cout<< M[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    cout << endl;
    vector<vector<int>> Out(Out_Size, vector<int>(Out_Size, 0));
    vector<vector<int>> Out_M(1, vector<int>(M_W, 0));
    Out_M = matrix(Kernel, M);
    cout << endl;
    for (int k = 0; k < Out_M[0].size(); ++k) {
        Out[k / Out_Size][k % Out_Size] = Out_M[0][k];
    }
    return Out;
}

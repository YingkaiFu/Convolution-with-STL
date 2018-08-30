//
// Created by yingkai on 18-8-29.
//

#ifndef CUDA_MATRIX_WITH_STL_H
#define CUDA_MATRIX_WITH_STL_H

#include "iostream"
#include "vector"
#include<assert.h>
#include<string>

using namespace std;

vector<vector<int>> matrix(vector<vector<int>> &M1, vector<vector<int>> &M2);


vector<vector<int>> conv(vector<vector<int>> &M1, vector<vector<int>> &M2, int Ksize, int padding);

#endif //CUDA_MATRIX_WITH_STL_H

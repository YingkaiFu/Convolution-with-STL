//
// Created by yingkai on 18-8-25.
//

#ifndef CUDA_CUDA_H
#define CUDA_CUDA_H
int cuda();

void matrix(int M1[2][4], int M2[4][3]);

void conv(int M1[6][6], int M2[3][3], int stride, int Ksize);
#endif //CUDA_CUDA_H

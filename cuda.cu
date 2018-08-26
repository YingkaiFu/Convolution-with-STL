#include <host_defines.h>
#include <cuda_runtime.h>
#include "iostream"
using namespace std;
__global__ void add(int a, int b, int *c)//kernel函数，在gpu上运行。
{
    *c = a + b;
}

int cuda() {
    int c;
    int *dev_c;
    cudaMalloc((void **) &dev_c, sizeof(int));
    add <<< 1, 1 >>> (2, 7, dev_c);
    cudaMemcpy(&c, dev_c, sizeof(int), cudaMemcpyDeviceToHost);
    cout << "2 + 7 = " << c << endl;
    cudaFree(dev_c);
    return 0;
}
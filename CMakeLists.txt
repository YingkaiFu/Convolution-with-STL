cmake_minimum_required(VERSION 3.10)
project(Cuda)
set(CMAKE_CXX_STANDARD 14)
find_package(CUDA REQUIRED)
include_directories(
        /usr/local/cuda/include
)
LINK_DIRECTORIES(
        /usr/local/cuda/lib64/
        )

cuda_add_executable(Cuda main.cpp cuda.cu cuda.h)
#pragma once
#define tab "\t"
#define TT template<typename T>
#define NN T* buffer = new T[n + 1];
#define NM T* buffer = new T[--n];
#define NR T** buffer = new T * [rows + 1];
#define RM T** buffer = new T* [--rows];

#define NC T* buffer = new T[cols + 1]{};
#define CM T* buffer = new T[cols - 1] {};
#define BI buffer[i] = arr[i];
#define DAI delete[] arr[i];arr[i] = buffer;
#define DAB delete[] arr; arr = buffer;
#define DR delete[] arr;return buffer;

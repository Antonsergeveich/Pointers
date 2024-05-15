#pragma once
template<typename T>
T* push_back(T arr[], int& n, T value);

template<typename T>
T* push_front(T arr[], int& n, T value);

template<typename T>
T* insert(T arr[], int& n, T value, int& index);

template<typename T>
T** push_row_front(T** arr, int& rows, const int cols);

template<typename T>
T** push_row_back(T** arr, int& rows, const int cols);

template<typename T>
T** insert_row(T** arr, int& rows, const int cols, int& index);

template<typename T>
void push_col_back(T** arr, const int rows, int& cols);

template<typename T>
void push_col_front(T** arr, const int rows, int& cols);

template<typename T>
void insert_col(T** arr, const int rows, int& cols, const int index);
#pragma once
template<typename T>
T* pop_back(T arr[], int& n);

template<typename T>
T* pop_front(T arr[], int& n);

template<typename T>
T* erase(T arr[], int& n, int& index);

template<typename T>
T** pop_row_back(T** arr, int& rows);

template<typename T>
T** pop_row_front(T** arr, int& rows);

template<typename T>
T** erase_row(T** arr, int& rows, int& index);

template<typename T>
void pop_col_back(T** arr, const int rows, int& cols);

template<typename T>
void pop_col_front(T** arr, const int rows, int& cols);

template<typename T>
void erase_col(T** arr, const int rows, int& cols, const int index);

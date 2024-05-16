#pragma once
#define TT template<typename T>
TT T* push_back(T arr[],int&n,T value);
TT T* push_front(T arr[],int&n,T value);
TT T* insert(T arr[],int&n,T value,int&index);
TT T** push_row_front(T**arr,int&rows, const int cols);
TT T** push_row_back(T**arr,int&rows,const int cols);
TT T** insert_row(T**arr,int&rows,const int cols,int&index);
TT void push_col_back(T**arr,const int rows,int&cols);
TT void push_col_front(T**arr,const int rows,int&cols);
TT void insert_col(T**arr,const int rows,int&cols,const int index);

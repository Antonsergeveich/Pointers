#pragma once
#define TT template<typename T>
TT T* pop_back(T arr[],int&n);
TT T* pop_front(T arr[],int&n);
TT T* erase(T arr[],int&n,int&index);
TT T** pop_row_back(T**arr,int&rows);
TT T** pop_row_front(T**arr,int&rows);
TT T** erase_row(T**arr,int&rows,int&index);
TT void pop_col_back(T**arr, const int rows,int&cols);
TT void pop_col_front(T**arr,const int rows,int&cols);
TT void erase_col(T**arr,const int rows,int&cols,const int index);

#include"Constants.h"
TT T*push_back(T arr[],int&n,T value){NN for(int i=0;i<n;i++)BI DAB arr[n]=value;n++;return arr;}
TT T*push_front(T arr[],int&n,T value){NN for(int i=0;i<n;i++)buffer[i+1]=arr[i];delete[]arr;buffer[0] = value;n++;return buffer;}
TT T* insert(T arr[],int&n,T value,int&index){NN for(int i=n;i>=index;i--)buffer[i+1]=arr[i];for (int i=0; i<index;i++)BI DAB arr[index]=value;n++;return arr;}
TT T** push_row_front(T**arr,int&rows,const int cols){NR for(int i=0;i<rows;i++)buffer[i+1]=arr[i];delete arr;buffer[0]=new T[cols]{};rows++;return buffer;}
TT T** push_row_back(T**arr,int&rows,const int cols){NR for (int i=0;i<rows;i++)BI delete[]arr;buffer[rows]=new T[cols]{};rows++;return buffer;}
TT T**insert_row(T**arr,int&rows,const int cols,int&index){NR for(int i=rows;i>=index;i--)buffer[i+1]=arr[i];for(int i=0;i<index;i++)BI delete[]arr;buffer[index]=new T[cols]{};rows++;return buffer;}
TT void push_col_back(T**arr,const int rows,int&cols){for(int i=0;i<rows;i++){NC for(int j=0;j<cols;j++)buffer[j]=arr[i][j];DAI}cols++;}
TT void push_col_front(T**arr,const int rows,int&cols){for (int i=0;i<rows;i++){NC for(int j=0;j<cols;j++)buffer[j+1]=arr[i][j];DAI}cols++;}
TT void insert_col(T** arr,const int rows,int&cols,const int index){for (int i = 0; i < rows; i++){NC for(int j=0;j<index;j++)buffer[j]=arr[i][j];for (int j=cols;j>=index;j--)buffer[j+1]=arr[i][j];DAI}cols++;}
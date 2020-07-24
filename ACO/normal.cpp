//
//  function.cpp
//  
//
//  Created by TzuChieh on 2020/3/18.
//  Copyright © 2020 TzuChieh. All rights reserved.
//

#include "function.hpp"
#include "normal.hpp"
using namespace std;
int* read(int &sum){//讀檔

    fstream file;
    int ind=0;
    file.open("readfile.txt",ios::in);
    int* temp=new int[510];
    while(file)
    {
        file>>temp[ind];
        ind++;
    }
    sum=ind-1;
    return temp;
}
void Print(int *arr,int len)//印出一維陣列
{
    for(int i=0;i<len;i++)
    {
        cout<<*(arr+i)<<' ';
    }
    cout<<endl<<endl;;
}
void PPrint(double *arr,int first,int second)
{
    for(int i=0;i<first;i++)
    {
        for(int j=0;j<second;j++)
        {
            cout<<*((double*)arr +first*i+j)<<' ';
        }
        cout<<endl;
    }
    cout<<endl;
}
void makearr(int *arr,int *input,int len)//將測資讀為整理好的陣列
{
    int chc=0;
    for(int i=0;i<len;i++)
    {
        for(int j=0;j<dim;j++)
        {
            *((int*)arr +dim*i+j)=*(input+chc);
            //cout<<*((int*)arr +dim*i+j)<<' ';
            chc++;
        }
        //cout<<endl<<endl;
    }
}
bool checkpathornot(int *arr,int loc,int len){//檢查是否有走過，走過為1沒走過為-1
    if(arr[loc]!=1)
        {
            return true;
        }
    else
        return false;
}

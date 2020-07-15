#include<stdio.h>
#include<fstream>
#include<iostream>
#include<sstream>
#include<stdlib.h>
#include <string.h>
#include<time.h>
using namespace std;
void create(int *arr,int item,int len)//隨機產生01
{
    for(int i=0;i<item;i++)
    {
        for(int j=0;j<len;j++)
        {
               *((int*)arr +len*i+j)=rand()%2;
               //cout<<*((int*)arr +len*i+j)<<' ';
        }
        //cout<<endl<<endl;
    }
}
void copyonepop(int *arr,int *temp,int index,int len)
{
    for(int i=0;i<len;i++)
    {
        temp[i]=*((int*)arr +len*index+i);
    }
}
void evaluate(int *arr,int item,int len,int *value)//評估所有染色體的適應度（也就是1有幾個)
{
   for(int i=0;i<item;i++)
    {
        int temp=0;
        for(int j=0;j<len;j++)
        {
           if(*((int*)arr +len*i+j)==1)
           {
            temp++;
           }
        }
        value[i]=temp;
    }

}
void findhalfbest(int *arr,int *value,int *best,int *globalbest,int item,int len,int &opt)//找出最優的一半染色體以及紀錄最佳解有幾個1
{
    int temp[item];
    int index[item];
    for(int i=0;i<item;i++)
    {
        temp[i]=value[i];
        index[i]=i;
    }
    for(int i=0;i<item;i++)//sort的概念
    {
        for(int j=i+1;j<item;j++)
        {
            if(temp[i]<temp[j])
            {
                int temp1=temp[i];
                int temp2=index[i];
                temp[i]=temp[j];
                temp[j]=temp1;
                index[i]=index[j];
                index[j]=temp2;
            }
        }
    }
    opt=temp[0];
    copyonepop(arr,globalbest,index[0],len);
    for(int i=0;i<item/2;i++)
    {
        best[i]=index[i];
       // cout<<best[i]<<' ';
    }
    //cout<<endl;
}
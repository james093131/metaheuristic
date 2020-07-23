#define alp 2.0//費洛蒙值
#define beta 5.0//距離係數
#define rho 0.1//衰退
#define Q 0.9
#define dim 3 //每一行有幾個數
#define initial_phermone 0.1//起始費洛蒙值
#define q0 0.1//機率選擇小於則選擇最優解
#include <math.h>
#include<stdio.h>
#include<fstream>
#include<iostream>
#include<sstream>
#include<stdlib.h>
#include <string.h>
#include<time.h>
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
    sum=(ind-1)/3;
    return temp;
}
void makearr(int *arr,int *input,int len)//將測資讀為整理好的陣列
{
    int chc=0;
    for(int i=0;i<len;i++)
    {
        for(int j=0;j<dim;j++)
        {
            *((int*)arr +dim*i+j)=*(input+chc);
            cout<<*((int*)arr +dim*i+j)<<' ';
            chc++;
        }
        cout<<endl<<endl;
    }
}
void phermoneinitial(double *pher,int len)
{
    for(int i=0;i<len;i++)
    {
        for(int j=0;j<len;j++)
        {
        *((double*)pher +len*(i)+j)=initial_phermone;
        }
    }
}
double fRand(double fMin, double fMax)
{
    return fMin + (rand() / ( RAND_MAX / (fMax-fMin) ) ) ;  
}
double distance_calculate(int x1 ,int y1,int x2,int y2){//計算兩點的距離
    double dis;
    dis=pow(x2-x1,2)+pow(y2-y1,2);
    dis=sqrt(dis);
    return dis;
}
void distance(double *arr ,int *city,int cityquan)
{
    for(int i=0;i<cityquan;i++)
    {
        for(int j=0;j<cityquan;j++)
        {
            if(i<=j)
                *((double*)arr +cityquan*(i)+j)=distance_calculate(*((int*)city +dim*(i)+1),*((int*)city +dim*(i)+2),*((int*)city +dim*(j)+1),*((int*)city +dim*(j)+2));
                *((double*)arr +cityquan*(j)+i)=*((double*)arr +cityquan*(i)+j);
        }
    }
}
void print2dim(double *arr,int len)
{
    for(int i=0;i<len;i++)
    {
        for(int j=0;j<len;j++)
        {
            cout<<*((double*)arr +len*(i)+j)<<' ';
        }
        cout<<endl;
    }
        
}
double formula(double *distance,double *phermone,int cityquan,int start,int point)//套用ACO費洛蒙與距離公式
{
    double dis=*((double*)distance +cityquan*(start)+point);
    double result=pow(1/dis,alp)+pow(*((double*)phermone +cityquan*(start)+point),beta);
    return result;
}
int probabilitytable(double *distance,double *phermone,int cityquan,int start,int *visit,int visitindex)
{
    double formularesult[cityquan];//儲存公式計算完的結果
    memset(formularesult,0,cityquan);
    for(int i=0;i<visitindex;i++)
    {
        formularesult[visit[visitindex]]=-1;//如果儲存過的則標註
    }
    double sum=0;
    int bestcity;//最好的城市編號
    double optimum=0.0;//最佳的城市解 
    for(int i=0;i<cityquan;i++)
    {
        if(i!=-1)
        {
            formularesult[i]=formula(distance,phermone,cityquan,start,i);
            if(formularesult[i]>optimum)
            {
                optimum=formularesult[i];
                bestcity=i;
            }
            formularesult[i]=formularesult[i]+sum;
            sum=formularesult[i];
        }
        else 
            formularesult[i]=-100;
    }
    for(int i=0;i<cityquan;i++){cout<<formularesult[i]<<endl;}
    cout<<sum<<endl;
    cout<<bestcity<<' '<<optimum<<endl;
    return bestcity;
}
void choosecity(double *formularesult,double sum,int *visit,int cityquan,int visitindex,int bestcity)//利用機率表選擇出城市
{
    double chc=fRand(0.0,1.0);
    if(chc<q0)
         visit[visitindex]=bestcity;
    else{
        double ran=fRand(0.0,sum);
        for(int i=0;i<cityquan;i++)
        {
            if(formularesult[i]<ran)
                visit[visitindex]=i;
        }
    }
}
int main(int argc,char *argv[]){
	double START,END;
    srand((unsigned)time(NULL));
	int iteration = atoi(argv[1]);
	int run = atoi(argv[2]);
	int r=0;//run
	int k=0;//在第幾個iteration找到最佳解
    int cityquan;//
    int *a=read(cityquan);//讀檔用的pointer
    int city[cityquan][dim];
    double pher[cityquan][cityquan];//紀錄費洛蒙表
    double phertemp[cityquan][cityquan];
    double distancetable[cityquan][cityquan];//儲存距離表
    cout<<cityquan<<endl;
    makearr((int*)city,a,cityquan);//紀錄好city的點和xy軸
    phermoneinitial( (double*)pher,cityquan);//起始費洛蒙濃度
    phermoneinitial( (double*)phertemp,cityquan);//起始費洛蒙濃度
    distance((double*)distancetable,(int*)city,cityquan);//製作距離表
    //初始化完成****************************************************************
    int bestcity=probabilitytable((double*)distancetable,(double*)pher,cityquan,0);
    int visit[cityquan];//造訪順序表
    visit[0]=0;
   
}
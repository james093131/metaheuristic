//
//  function.cpp
//  
//
//  Created by TzuChieh on 2020/3/18.
//  Copyright © 2020 TzuChieh. All rights reserved.
//
#include "function.hpp"
#include "normal.hpp"
void phermoneinitial(double *pher,int len)
{
    for(int i=0;i<len;i++)
    {
        for(int j=0;j<len;j++)
        {
        *((double*)pher +len*(i)+j)=initial_pher;
        }
    }
}
void phermoneupdate(int *path,double *pher,int dis,int len,double dec){

    for(int i=0;i<len;i++)
    {
            int k=path[i]-1;
            int y=path[i+1]-1;
            *((double*)pher +len*(k)+y)=*((double*)pher +len*(k)+y)*(1-dec)+dec*(double)Q/dis;
            *((double*)pher +len*(y)+k)=*((double*)pher +len*(k)+y);
    }
}
void phermonermix(double *pher,double *phertemp,int lenx,int leny)
{
    for(int i=0;i<lenx;i++)
    {
        for(int j=0;j<leny;j++)
        {
            if(lenx>=leny)
            {
            //*((double*)pher +lenx*(i)+j)=*((double*)pher +lenx*(i)+j)*decline+*((double*)phertemp +lenx*(i)+j);
                if(*((double*)phertemp +lenx*(i)+j)<*((double*)phertemp +lenx*(j)+i))
                {
                    *((double*)pher +lenx*(i)+j)=*((double*)phertemp +lenx*(i)+j);
                    *((double*)pher +lenx*(j)+i)=*((double*)phertemp +lenx*(i)+j);
                }
                else{
                    *((double*)pher +lenx*(i)+j)=*((double*)phertemp +lenx*(j)+i);
                    *((double*)pher +lenx*(j)+i)=*((double*)phertemp +lenx*(j)+i);
                }
                if(*((double*)pher +lenx*(i)+j)<initial_pher){
                    *((double*)pher +lenx*(i)+j)=initial_pher;
                    *((double*)pher +lenx*(j)+i)=initial_pher;
                }
                    
            }
        }
    }
}
int solutionconstruct(int *arr,double *pher,int ini,int len,int *check,double &dis,double * distable,double alpha,double beta){//用輪盤的方式找下一點
    double sum=0;
    double temp[len];
    memset(temp,0,sizeof(temp));
    for(int i=0;i<len;i++)
    {
        if(i!=ini-1&&checkpathornot(check,i,len)){
            //double dis=calculatedistance(*((int*)arr +dim*(ini-1)+1),*((int*)arr +dim*(ini-1)+2),*((int*)arr +dim*(i)+1),*((int*)arr +dim*(i)+2));//計算兩點的距離
            double dis=*((double*)distable +len*(ini-1)+i);
            temp[i]=sum+pow(*((double*)pher +len*(ini-1)+(i)),alpha)*pow(1/dis,beta);//用疊加的方式來進行方便後續機率切割作業
            sum=temp[i];
        }
        else
            temp[i]=-10000;
    }
    
    //cout<<sum<<endl;
    //for(int i=0;i<len;i++){cout<<i+1<<' '<<temp[i]<<endl;}
    for(int i=0;i<len;i++)
    {
        temp[i]=temp[i]/sum;//變成機率
    }
    //for(int i=0;i<len;i++){cout<<i+1<<' '<<temp[i]<<endl;}
      double x = (1 - 0) * rand() / (RAND_MAX + 1.0) + 0;
    //cout<<'x'<<' '<<x<<endl;
    int choice=-1;
    for(int i=0;i<len;i++)
    {
        if(x<temp[i]){
            choice=i+1;
            break;
        }
    }
    //dis+=calculatedistance(*((int*)arr +dim*(ini-1)+1),*((int*)arr +dim*(ini-1)+2),*((int*)arr +dim*(choice-1)+1),*((int*)arr +dim*(choice-1)+2));//計算最後一個點回到起始點的距離
    dis+=*((double*)distable +len*(ini-1)+choice-1);
    //cout<<choice<<endl;
    return choice;
}
void oneant(int *arr,double *pher,int *path,int ini,int len,double &dis,double *distable,double alpha,double beta){
    //010101
    int check[len];
    memset(check,-1,sizeof(check));
    check[ini-1]=1;
    path[0]=ini;
    path[len]=ini;
    int i=1;
    int k=ini;
    while(i<len){
    k=solutionconstruct(arr,pher,k,len,check,dis,distable,alpha,beta);
    path[i]=k;
    check[k-1]=1;
    i++;
    }
    //dis+=calculatedistance(*((int*)arr +dim*(ini-1)+1),*((int*)arr +dim*(ini-1)+2),*((int*)arr +dim*(path[len-1]-1)+1),*((int*)arr +dim*(path[len-1]-1)+2));
    dis+=*((double*)distable +len*(ini-1)+path[len-1]-1);
    //Print(path,len+1);
}
void randompath(int *arr,double &path,int *order,int len,double *distable,int ini)
{
    int check[len];
    int k=1;
    memset(check,-1,sizeof(check));
    check[ini-1]=1;//用陣列ind去對所以要減一
    order[0]=ini;
    order[len]=ini;
    int temppoint=ini-1;
    int c = 0;
    while(k<len)
    {
        c=rand()%(len);//隨機0-len-1
        while(!checkpathornot(check,c,len))
        {
            c=rand()%(len);
        }
        //path+=calculatedistance(*((int*)arr +dim*(temppoint)+1),*((int*)arr +dim*(temppoint)+2),*((int*)arr +dim*(c)+1),*((int*)arr +dim*(c)+2));//計算兩點的路徑長
        path+=*((double*)distable +len*(temppoint)+c);
        check[c]=1;
        temppoint=c;
        order[k]=temppoint+1;
        k++;
    }
    //path+=calculatedistance(*((int*)arr +dim*(start-1)+1),*((int*)arr +dim*(start-1)+2),*((int*)arr +dim*(c)+1),*((int*)arr +dim*(c)+2));//最後一點回到1
    path+=*((double*)distable +len*(ini-1)+c);

}
void bestphermoneupdate(int *bestpath,double *pher,int dis,int len,double dec){

    for(int i=0;i<len;i++)
    {
            int k=bestpath[i]-1;
            int y=bestpath[i+1]-1;
            *((double*)pher +len*(k)+y)=*((double*)pher +len*(k)+y)*(1-dec)+dec*(double)Q/dis;
            *((double*)pher +len*(y)+k)=*((double*)pher +len*(y)+k)*(1-dec)+dec*(double)Q/dis;
    }
}

double distance_calculate(int x1 ,int y1,int x2,int y2){//計算兩點的距離
    double dis;
    dis=pow(x2-x1,2)+pow(y2-y1,2);
    dis=sqrt(dis);
    return dis;
}
void distancecal(double *arr ,int *city,int cityquan)
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
double pathcal(int *path,double *distancetable,int len)
{
    double dis=0;
    for(int i=0;i<len-1;i++)
    {
        dis+=*((double*)distancetable +len*(path[i]-1)+path[i+1]-1);
    }
    dis+=*((double*)distancetable +len*(path[len-1]-1)+path[len]-1);
    return dis;
}
void twoopt(int *path,int len,double &distance,double *distancetable)
{

    double curr=0;
    double after=0;
    for(int i=1;i<len-3;i++)
    {
        for(int j=i+3;j<len-1;j++)
        {
            int k=i;
            int y=j;
            curr=0;
            after=0;
            curr+=*((double*)distancetable +len*(path[k]-1)+path[k+1]-1);
            curr+=*((double*)distancetable +len*(path[y]-1)+path[y-1]-1);
            after+=*((double*)distancetable +len*(path[y]-1)+path[k+1]-1);
            after+=*((double*)distancetable +len*(path[k]-1)+path[y-1]-1);
            if(after<curr)
            {
                //cout<<"curr"<<curr<<endl;
                //cout<<"after"<<after<<endl;
                //cout<<"path"<<k<<' '<<y<<endl;
                while(k<y)
                {
                    int temp=path[k+1];
                    path[k+1]=path[y-1];
                    path[y-1]=temp;
                    k++;
                    y--;
                }
                distance=pathcal(path,distancetable,len);
            }
        }
    }
}

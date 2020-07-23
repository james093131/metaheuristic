#define alp 2.0//費洛蒙值
#define beta 5.0//距離係數
#define rho 0.1//衰退
#define Q 0.9
#define dim 3 //每一行有幾個數
#define initial_phermone 0.1//起始費洛蒙值
#include "../normal/normal.hpp"
#include "math.h"
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
double distance_calculate(int x1 ,int y1,int x2,int y2){//計算兩點的距離
    double dis;
    dis=pow(x2-x1,2)+pow(y2-y1,2);
    dis=sqrt(dis);
    return dis;
}

int main(int argc,char *argv[]){
	double START,END;
    srand( static_cast<unsigned int>(time(nullptr)));
	int iteration = atoi(argv[1]);
	int run = atoi(argv[2]);
	int r=0;//run
	int k=0;//在第幾個iteration找到最佳解
    int len;
    int city[len][dim];
    int *a=read(len);//讀檔用的pointer
    double pher[len][len];//紀錄費洛蒙表
    double distancetable[len][len];
    phermoneinitial( (double*)pher,len);//起始費洛蒙濃度
    cout<<len<<endl;
    makearr((int*)city,a,len);//紀錄好city的點和xy軸
    
}
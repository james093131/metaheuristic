#include "SAfunction.hpp"
void NeighborSelection(char *arr,int size){
	int ran=rand()%size;
	if(arr[ran]=='1')
		arr[ran]='0';
	else
		arr[ran]='1';
}
double SAformula(int newsol  ,int currsol)
{
    double pa=exp((newsol-currsol)/temperature);
    return pa;
}
double randomminmax()
{
    double r = (randomnum_max - randomnum_min) * rand() / (RAND_MAX + 1.0) + randomnum_min;
    return r;
}
void update(double r,double pa,char *newarr,char *currarr,int len,int &opt,int curropt,double &T)
{
	T=A*T;
    if(pa>r)
    {
		for(int i=0;i<len;i++)
		{
			currarr[i]=newarr[i];
		}
		opt=curropt;
	}
}
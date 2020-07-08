#include "../normal/normal.hpp"
#include<math.h>
int SAformula(int newsol  ,int curr,double temperature)
{
    double pa =exp((newsol-curr)/temperature);
    return pa;
}
double randomminmax(double min ,double max)
{
    double r = (max - min) * rand() / (RAND_MAX + 1.0) + min;
    return r;
}
void update(double r,double pa,char *newarr,char *currarr,int len,int &opt)
{
    if(pa>r)
    {
		for(int i=0;i<len;i++)
		{
			currarr[i]=newarr[i];
		}
        int curropt=Evaluate(newarr,len);
		opt=curropt;
	}
    
}
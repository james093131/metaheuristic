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
void SA(char *arr,int &opt,int iteration,int len,double T)
{
		int k=0;
		while(k<iteration)
		{
			char temp[len];
			for(int i=0;i<len;i++)
			{
				temp[i]=arr[i];
			}
			NeighborSelection(temp,len);
            int curropt=Evaluate(temp,len);
            double pa =SAformula(curropt,opt);
            double r=randomminmax();
            update(r,pa,temp,arr,len,opt,curropt,T);
			cout<<"iteration"<<k+1<<":"<<opt<<endl;
			if(opt==len)
				break;			
			k++;
		}
}
void run(char *arr,int &opt,int iteration,int len,double T,int run,int *result)
{
	int r=0;
	while(r<run)
	{
		cout<<len<<"bits"<<endl;
		char  arr[len];
		create(arr,len);
		opt=Evaluate(arr,len);
		SA(arr,opt,iteration,len,T);
		result[r]=opt;
		r++;
	}
}
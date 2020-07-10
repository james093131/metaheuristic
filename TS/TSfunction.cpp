#include "TSfunction.hpp"
void tabumake(queue<char> &tabulist,char *arr,int len,int tabusize)
{
	if(tabulist.size()>=tabusize*len)
	{
		for(int i=0;i<len;i++)
		{
			tabulist.pop();
		}
	}
	for(int i=0;i<len;i++)
	{
		tabulist.push(arr[i]);
	}
}
int MemoryNeighborSelection(char *arr,int len)
{
	int ran=rand()%len;
	if(arr[ran]=='1')
		arr[ran]='0';
	else
		arr[ran]='1';
	return ran;
}
void NoneTabuNeighborSelection(char *arr,int len,queue<char>tabulist,int tabusize,int &samecount)
{
	int k=0;
	int changeindex=MemoryNeighborSelection(arr,len);
	while(!tabulist.empty())
	{
	
		if(k==len)
		{
			samecount++;
			if(arr[changeindex]=='1')
				arr[changeindex]='0';
			else 
				arr[changeindex]='1';
			tabumake(tabulist,arr,len,tabusize);
			NoneTabuNeighborSelection(arr,len,tabulist,tabusize,samecount);
			break;
		}
		else if(tabulist.front()!=arr[k])
		{
			while(k<len)
			{
				tabulist.pop();
				k++;
			}
			k=0;
		}
		else{
			tabulist.pop();
			k++;
		}
	}

}
void TABU(char *arr,int len,queue<char>tabulist,int tabusize,int &samecount,int opt,int iteration,int r,int *result)
{
	int k=0;//在第幾個iteration找到最佳解
	while(k<iteration)
	{
		char temp[len];
		for(int i=0;i<len;i++)
		{
			temp[i]=arr[i];
		}
		NoneTabuNeighborSelection(temp,len,tabulist,tabusize,samecount);
		tabumake(tabulist,temp,len,tabusize);				
		int curropt=Evaluate(temp,len);
		compare(arr,temp,len,opt,curropt);
		cout<<"iteration "<<k+1<<":"<<opt<<endl;
		if(opt==len)
			break;		
		k++;
	}
	result[r]=opt;
}
void RUN(char *arr,int len,queue<char>tabulist,int tabusize,int &samecount,int opt,int iteration,int run,int *result)
{
	int r=0;
	while(r<run)
	{
		cout<<len<<"bits"<<endl;
		char  arr[len];
		create(arr,len);
		opt=Evaluate(arr,len);
		TABU(arr,len,tabulist,tabusize,samecount,opt,iteration,r,result);
		r++;
	}
}
#define tabulistcoeff 0.05
#include "../normal/normal.hpp"
#include <queue> 
//#include "../HC/HCfunction.hpp"
//cmd執行方式 ./TS 100(bit數)  1000(iteration) 20(run) 
void tabumake(queue<char> &tabulist,char *arr,int len,int tabusize)//checkok!
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
int main(int argc,char *argv[]){
	double START,END;
	srand(time(NULL));
	int len = atoi(argv[1]);
	int iteration = atoi(argv[2]);
	int run = atoi(argv[3]);
	int runresult[run];
	int r=0;//run
	int k=0;//在第幾個iteration找到最佳解
	int tabusize=len*tabulistcoeff+1;
	int samecount=0;	
	queue<char> tabulist;
	char  onemax[len];
	create(onemax,len);
	tabumake(tabulist,onemax,len,tabusize);
	int opt=Evaluate(onemax,len);
	while(k<iteration)
	{
		char temp[len];
		memcpy(temp,onemax,sizeof(onemax));
		NoneTabuNeighborSelection(temp,len,tabulist,tabusize,samecount);
		tabumake(tabulist,temp,len,tabusize);				
		int curropt=Evaluate(temp,len);
		compare(onemax,temp,len,opt,curropt);
		cout<<"iteration "<<k+1<<":"<<opt<<endl;
		if(opt==len)
			break;		
		k++;
	}
	cout<<"Same Situation "<<samecount<<endl;	

}






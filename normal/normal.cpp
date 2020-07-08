#include "normal.hpp"
void create(char *arr,int size)
{
	for(int i=0;i<size;i++)
	{
  	int a=rand()%2;
    char c =a+'0';
    arr[i]=c;
    }
}
 void Print(char *arr,int size){
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<' ';
	}
	cout<<endl;
} 
int Evaluate(char *arr,int size)
{
	int optimal=0;
	for(int i=0;i<size;i++)
	{
		if(arr[i]=='1')
			optimal++;
	}
	return optimal;
}
void add(char *arr,int len)
{
	int i=len-1;
	int chc=1;
	while(chc){
    	if(arr[i]=='1')
		{
			arr[i]='0';
			i--;
		}
		else if (arr[i]=='0')
		{
			arr[i]='1';
			chc=0;
			break;
		}
	} 
}
void sub (char *arr,int len)
{
	int i=len-1;
	int chc=1;
	while(chc){
    	if(arr[i]=='1')
		{
			arr[i]='0';
			chc=0;
			break;
		}
		else if (arr[i]=='0')
		{
			arr[i]='1';
			i--;
		}
	} 
}
int avg(int *arr,int len)
{
	int sum=0;
	for(int i=0;i<len;i++)
	{
		sum+=arr[i];
		cout<<"iteration"<<i+1<<':'<<arr[i]<<endl;
	}
	int avg=sum/len;
	return avg;
}
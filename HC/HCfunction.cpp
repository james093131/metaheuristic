#include "C:\Users\chieh\Documents\metaheuristic\normal.cpp"

void Enumnext(char *arr,int len){
	int i=len-1;
	int ran=rand()%2;
	if (ran==1)
	{
		add(arr,len);
	}
	else{
		sub(arr,len);
	}
	
}
void NeighborSelection(char *arr,int size){
	int ran=rand()%size;
	if(arr[ran]=='1')
		arr[ran]='0';
	else
		arr[ran]='1';
    
}
void compare(char *arr,char *temp,int len,int &opt,int curropt)
{
	if(curropt>=opt)
	{
		for(int i=0;i<len;i++)
		{
			arr[i]=temp[i];
		}
		opt=curropt;
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
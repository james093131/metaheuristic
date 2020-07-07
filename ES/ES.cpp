#include "../normal/normal.hpp"

int main(int argc,char *argv[]){
	double START,END;
	srand(time(NULL));
	int len = atoi(argv[1]);
	int time = atoi(argv[2]);
	char onemax[len];
	char temp[len];
	memset(onemax,'0',sizeof(onemax));
	memset(temp,'0',sizeof(temp));
	//Print(temp,len);
	int opt=Evaluate(onemax,len);
	START = clock();
	while( ((END - START) / CLOCKS_PER_SEC)<time){
		add(temp,len);
		//Print(temp,len);
		int temp2=Evaluate(temp,len);
		if(temp2>=opt)
		{
            opt=temp2;
		    memcpy(onemax,temp,sizeof(temp));
		}
        END=clock();
	}
	Print(onemax,len);
	cout<<"Quantity:"<<endl<<opt<<endl;
	cout<<"Execution Time:";
    cout<<(END - START) / CLOCKS_PER_SEC<<"(s)"<<endl;
}

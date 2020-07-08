#include "SAfunction.cpp"
int main(int argc,char *argv[]){
	double START,END;
	srand(time(NULL));
	int len = atoi(argv[1]);
    int iteration= atoi(argv[2]);
    int run = atoi(argv[3]);
	char onemax[len];
	int runresult[run];
	int runtime=0;//run
	int k=0;//在第幾個iteration找到最佳解
	while(runtime<run){
		cout<<len<<"bits"<<endl;
		char  onemax[len];
		create(onemax,len);
		int opt=Evaluate(onemax,len);
		k=0;
		while(k<iteration)
		{
			char temp[len];
			memcpy(temp,onemax,sizeof(onemax));
			NeighborSelection(temp,len);
            int curropt=Evaluate(temp,len);
            double pa =SAformula(opt,curropt);
            double r=randomminmax();
            update(r,pa,temp,onemax,len,opt,curropt);
			cout<<"iteration"<<k+1<<":"<<opt<<endl;
			if(opt==len)
				break;			
			k++;
		}
		runresult[runtime]=opt;
		runtime++;
	}
}
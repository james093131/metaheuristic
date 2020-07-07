#include "HCfunction.cpp"
//cmd執行方式 ./HC 100(bit數)  1000(iteration) 20(run) r(方法)
int main(int argc,char *argv[]){
	double START,END;
	srand(time(NULL));
	int len = atoi(argv[1]);
	int iteration = atoi(argv[2]);
	int run = atoi(argv[3]);
	int runresult[run];
	int r=0;//run
	int k=0;//在第幾個iteration找到最佳解
	while(r<run){
		cout<<len<<"bits"<<endl;
		char  onemax[len];
		create(onemax,len);
		int opt=Evaluate(onemax,len);
		k=0;
		while(k<iteration)
		{
			char temp[len];
			memcpy(temp,onemax,sizeof(onemax));
			if(argv[4] == std::string("r"))
				NeighborSelection(temp,len);
			else 
				Enumnext(temp,len);
			int curropt=Evaluate(temp,len);
			compare(onemax,temp,len,opt,curropt);
			cout<<"iteration"<<k+1<<":"<<opt<<endl;
			if(opt==len)
				break;			
			k++;
		}
		runresult[r]=opt;
		r++;
	}
	int avgiteration=avg(runresult,r);
	cout<<"Average Optima :"<<avgiteration<<endl;
	fstream file;//寫檔
	file.open("LRhc.txt",ios::app);
	file<<iteration<<' '<<avgiteration<<endl;
}






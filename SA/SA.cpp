#include "SAfunction.cpp"
#define temperature 1
#define alpha 0.9
#define randomnum_max 1
#define randomnum_min 0
int main(int argc,char *argv[]){
	double START,END;
	srand(time(NULL));
	int len = atoi(argv[1]);
    int run = atoi(argv[2]);
	char onemax[len];
	char temp[len];
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
			NeighborSelection(temp,len);
            double pa =SAformula(temp,onemax,temperature);
            double r=randomminmax(randomnum_min,randomnum_max);
            update(r,pa,temp,onemax,len,opt);
			cout<<"iteration"<<k+1<<":"<<opt<<endl;
			if(opt==len)
				break;			
			k++;
		}
		runresult[r]=opt;
		r++;
	}
}
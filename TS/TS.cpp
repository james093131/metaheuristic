#include "TSfunction.hpp"

int main(int argc,char *argv[]){
	double START,END;
	srand(time(NULL));
	int len = atoi(argv[1]);
	int iteration = atoi(argv[2]);
	int run = atoi(argv[3]);
	int runresult[run];
	int r=0;//run
	int tabusize=len*tabulistcoeff+1;
	int samecount=0;	
	queue<char> tabulist;
	char  onemax[len];
	create(onemax,len);
	tabumake(tabulist,onemax,len,tabusize);
	int opt=Evaluate(onemax,len);
	RUN(onemax,len,tabulist,tabusize,samecount,opt,iteration,run,runresult);
	int avg_optimim=avg(runresult,run);
	cout<<"Average optima :"<<avg_optimim<<endl;
	cout<<"Average same situation "<<samecount/run<<endl;
}






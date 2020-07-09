//cmd執行方式 ./SA 100(bit數)  1000(iteration) 30(run) 
#include "SAfunction.hpp"
int main(int argc,char *argv[]){
	double START,END;
	srand(time(NULL));
	int len = atoi(argv[1]);
    int iteration= atoi(argv[2]);
    int runtime = atoi(argv[3]);
	char onemax[len];
	int runresult[runtime];
	int opt=0;
	double T=temperature;
	int k=0;//在第幾個iteration找到最佳解
	run(onemax,opt,iteration,len,T,runtime,runresult);
	int avgiteration=avg(runresult,runtime);
	cout<<"Average Optima :"<<avgiteration<<endl;
	fstream file;//寫檔
	file.open("SAresult.txt",ios::app);
	file<<iteration<<' '<<avgiteration<<endl;
}
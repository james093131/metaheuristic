#include "function.hpp"
double formula(double *x,int len)
{
    double sigma1=0;
    double sigma2=0;
    for(int i=0;i<len;i++)
    {
        sigma1+=pow(x[i],2);
        sigma2+=cos(2*M_PI*x[i]);
    }
    double re= -20*(exp((-0.2)*sqrt(sigma1/len)))-exp(sigma2/len)+20+exp(1);
    return re;
}
void randomstart(double *DE_POP,int pop,int len)
{
    for(int i=0;i<pop;i++)
    {
        double dim[len];
        int j=0;
        while(j<len-1)
        {
         dim[j]=(max - (min)) * rand() / (RAND_MAX + 1.0) + (min);
         j++;
        }
        dim[len-1]=formula(dim,len-1);
        for(int k=0;k<len;k++)
        {
            *((double*)DE_POP +len*(i)+k) = dim[k];
        }
    }
    
}
void Vector_randchoose(int x,int &a,int &b,int &c,int i)
{
    while(a==i)
    {
        a = rand() % (x-1 + 1)+0  ;
    }
    while(b==a||b==i)
    {
        b = rand() % (x-1 + 1)+0  ;
    }
    while(c==b||c==a||b==i)
    {
        c = rand() % (x-1 + 1)+0  ;
    }
}
void Vector_make(double *DE_pop,double *DE_Vector,int pop ,int dim)
{
    int i=0;
    while(i<pop)
    {
        for(int j=0;j<dim-1;j++)
        {
            int a = rand() % (pop-1 + 1)+0  ;
            int b = rand() % (pop-1 + 1)+0  ;
            int c = rand() % (pop-1 + 1)+0  ;
            Vector_randchoose(pop,a,b,c,i);
            *((double*)DE_Vector +(dim-1)*(i)+j) = *((double*)DE_pop +dim*(a)+j)+F*(*((double*)DE_pop +dim*(b)+j)-*((double*)DE_pop +dim*(c)+j));
            if(*((double*)DE_Vector +(dim-1)*(i)+j)>max)
            {
                *((double*)DE_Vector +(dim-1)*(i)+j)=max;
            }
            else if(*((double*)DE_Vector +(dim-1)*(i)+j)<min)
            {
                *((double*)DE_Vector +(dim-1)*(i)+j)=min;
            }
        }
        i++;
    }
}
void crossover(double *u,double *x,double *v,int whichpop,int len)
{
        double a=(1 - (0)) * rand() / (RAND_MAX + 1.0) + (0);
        int i=0;
        while(i<len-1)
        {
            if(a>crossoverrate)
            {
                u[i]= *((double*)x +(len)*(whichpop)+i);
            }
            else if(i==whichpop)
            {
                u[i]= *((double*)v +(len)*(whichpop)+i);

            }
            else 
            {
                u[i]= *((double*)v +(len)*(whichpop)+i);
            }
            i++;
        }
        u[len-1]=formula(u,len-1);//計算當個pop的結果
}
void select(double *DE_pop,double *DE_Vector,int pop,int len)
{
    
    for(int i=0;i<pop;i++)
    {
        double u[len];
        crossover(u,DE_pop,DE_Vector,i,len);
        if(u[len-1] < *((double*)DE_pop +(len)*(i)+len-1))
        {
            for(int j=0;j<len;j++)
            {
                *((double*)DE_pop +(len)*(i)+j)=u[j];
            }
        }
    }
}
void Evaluation(double *DE_pop,double *best,double &optimum,int pop,int len)
{
    int loc=-1;
    for(int i=0;i<pop;i++)
    {
        if(optimum > *((double*)DE_pop +(len)*(i)+len-1))
        {
            optimum = *((double*)DE_pop +(len)*(i)+len-1);
            loc=i;
        }
    }
    if(loc!=-1)
    {
        for(int k=0;k<len-1;k++)
        {
            best[k]=*((double*)DE_pop +(len)*(loc)+k);
        }
    }
}
void finaloutput(double optimum,double *best,int dim,int iteration,int checkpoint,int run)
{
    cout<<"---------------------------------------"<<endl;
    cout<<"Run : "<<run<<endl;
    cout<<"dimensions : "<<dim<<endl;
    cout<<"Optimum : "<<optimum<<endl;
    cout<<"coordinate : "<<endl<<'(';
    for(int i=0;i<dim-2;i++)
    {
        cout<<best[i]<<',';
    }
    cout<<best[dim-2]<<')'<<endl;
    cout<<"---------------------------------------"<<endl;
   
}
void output_txt(double RUN_optimum ,double AVG_optimum,double *best,int dim,int AVG_iteration,int ITE,int checkpoint,int run,int pop,double START,double END)
{
    fstream file;//寫檔
    file.open("DE_Result.txt",ios::app);
   
    file<<"Run : "<<run<<endl;
    file<<"Population : "<<pop<<endl; 
    file<<"Dimensions : "<<dim<<endl;
    if(checkpoint==1)
    {
        file<<"The Average Iteration that Optimum is less than 0.00001 : "<< AVG_iteration <<endl;
        cout<<"The Average Iteration that Optimum is less than 0.00001 : "<< AVG_iteration <<endl;
    }
    else
    {
        file<<"Within a "<<ITE<<" Iteration can not find the average optimum is less than 0.00001"<<endl;
        cout<<"Within a "<<ITE<<" Iteration can not find the average optimum is less than 0.00001"<<endl;
    }
    file << "Execution Time: " << (END - START) / CLOCKS_PER_SEC << "(s)" << endl;
    file<<"Average Optimum : "<<AVG_optimum<<endl;
    file<<"Best Optimum : "<<RUN_optimum<<endl;
    file<<"Best Optimum coordinate : "<<endl<<'(';
    for(int i=0;i<dim-2;i++)
    {
        file<<best[i]<<" , ";
    }
    file<<best[dim-2]<<')'<<endl;
    file<<"----------------------------------------------------"<<endl;
    cout<<"Run : "<<run<<endl;
    cout<<"Population : "<<pop<<endl; 
    cout<<"Dimensions : "<<dim<<endl;
    cout << "Execution Time: " << (END - START) / CLOCKS_PER_SEC << "(s)" << endl;
    cout<<"Average Optimum : "<<AVG_optimum<<endl;
    cout<<"Best Optimum : "<<RUN_optimum<<endl;
    cout<<"Best Optimum coordinate : "<<endl<<'(';
    for(int i=0;i<dim-2;i++)
    {
        cout<<best[i]<<" , ";
    }
    cout<<best[dim-2]<<')'<<endl;
    cout<<"----------------------------------------------------"<<endl;
}
double AVG(double *result,int run)
{
    double a=0;
    for(int i=0;i<run;i++)
    {
        a+=result[i];
    }
    a=a/run;
    return a;
}
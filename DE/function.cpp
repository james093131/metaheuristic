#include "function.hpp"
double  formula(double x,double y)
{
    double re=-20*(exp((-0.2)*sqrt((pow(x,2)+pow(y,2))/2)))-exp((cos(2*M_PI*x)+cos(2*M_PI*y))/2)+20+exp(1);
    return re;
}
void randomstart(double *DE_POP,int x,int y)
{
    for(int i=0;i<x;i++)
    {
        double a=(max - (min)) * rand() / (RAND_MAX + 1.0) + (min);
        double b=(max - (min)) * rand() / (RAND_MAX + 1.0) + (min);
        double c=formula(a,b);
        *((double*)DE_POP +y*(i)+0) = a;//隨機x
        *((double*)DE_POP +y*(i)+1) = b;//隨機ｙ
        *((double*)DE_POP +y*(i)+2) = c;//結果
    }
    
}
void Vector_randchoose(int x,int &a,int &b,int &c)
{
    
    while(b==a)
    {
        b = rand() % (x-1 + 1)+0  ;
    }
    while(c==b||c==a)
    {
        c = rand() % (x-1 + 1)+0  ;
    }
}
void Vector_make(double *DE_pop,double *DE_Vector,int x ,int y)
{
    int i=0;
    while(i<x)
    {
        int a = rand() % (x-1 + 1)+0  ;
        int b = rand() % (x-1 + 1)+0  ;
        int c=rand() % (x-1 + 1)+0  ;
        Vector_randchoose(x,a,b,c);
        cout<<a<<' '<<b<<' '<<c<<endl;
        for(int j=0;j<dim-1;j++)
        {
            *((double*)DE_Vector +dim*(i)+j)= *((double*)DE_pop +dim*(a)+j)+F*(*((double*)DE_pop +dim*(b)+j)-*((double*)DE_pop +dim*(c)+j));//怪怪
            cout<<*((double*)DE_Vector +dim*(i)+j)<<endl;
        }
        i++;
    }
}
// void crossover(double *DE_pop,double *DE_Vector,int x)
// {
//     double temp[pop][dim-1];
//     double a=(1 - (0)) * rand() / (RAND_MAX + 1.0) + (0);
//     for(int i=0;i<pop;i++)
//     {
//         if(*((double*)DE_Vector +dim*(i)+dim-1) < *((double*)DE_pop +dim*(i)+dim-1))
//         {
//             for(int j=0;j<dim;j++)
//             {
//                  *((double*)DE_pop +dim*(i)+j)=*((double*)DE_Vector +dim*(i)+j);
//             }
//         }
//     }

// }
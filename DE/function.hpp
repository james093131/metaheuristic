#include<iostream>
#include<fstream>
#include<sstream>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include <math.h>
#include <stdio.h>
#define max 40.000
#define min -40.000
#define crossoverrate 0.8
#define F 0.8
//#define ITE 1000
using namespace std;
double  formula(double *x,int len);
void randomstart(double *,int ,int );
void Vector_randchoose(int x,int &a,int &b,int &c,int i);
void Vector_make(double *DE_pop,double *DE_Vector,int x ,int y);
void crossover(double *u,double *x,double *v,int whichpop,int len);
void select(double *DE_pop,double *DE_Vector,int pop,int len);
void Evaluation(double *DE_pop,double *best,double &optimum,int pop,int len);
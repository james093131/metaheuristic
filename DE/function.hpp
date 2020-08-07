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
using namespace std;
double  formula(double *x,int len);//ackley公式
void randomstart(double *,int ,int );//隨機開始位置
void Vector_randchoose(int x,int &a,int &b,int &c,int i);//choose a b c 
void Vector_make(double *DE_pop,double *DE_Vector,int x ,int y);//Make v 
void crossover(double *u,double *x,double *v,int whichpop,int len);//Make child
void select(double *DE_pop,double *DE_Vector,int pop,int len);//Choose the better one from Parent and Child
void Evaluation(double *DE_pop,double *best,double &optimum,int pop,int len);//衡量當前解，並儲存最優解
void finaloutput(double optimum,double *best,int dim,int iteration,int checkpointint ,int run);//輸出
void output_txt(double RUN_optimum ,double AVG_optimum,double *best,int dim,int AVG_iteration,int ITE,int checkpoint,int run,int pop,double START,double END);
double AVG(double *result,int run);
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
#define dim 3
#define crossoverrate 0.8
#define F 0.8
//#define ITE 1000
using namespace std;
double  formula(double ,double );
void randomstart(double *,int ,int );
void Vector_randchoose(int x,int &a,int &b,int &c);
void Vector_make(double *DE_pop,double *DE_Vector,int x ,int y);

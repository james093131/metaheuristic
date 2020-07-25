//
//  function.hpp
//  ACOXCODE
//
//  Created by TzuChieh on 2020/3/18.
//  Copyright © 2020 TzuChieh. All rights reserved.
//

#ifndef function_hpp
#define function_hpp
#include <stdio.h>
void phermoneinitial(double *pher,int len);
void phermoneupdate(int *path,double *pher,int dis,int len,double dec);
//void phermonermix(double *pher,double *phertemp,int lenx,int leny);
int solutionconstruct(int *arr,double *pher,int ini,int len,int *check,double &dis,double * distable,double alpha,double beta);//用輪盤的方式找下一點
void oneant(int *arr,double *pher,int *path,int ini,int len,double &dis,double *distable,double alpha,double beta);
void randompath(int *arr,double &path,int *order,int len,double *distable,int ini);
void bestphermoneupdate(int *bestpath,double *pher,int dis,int len,double dec);
void distancecal(double *arr ,int *city,int cityquan);
void twoopt(int *path,int len,double &distance,double *distancetable);
double pathcal(int *path,double *distancetable,int len);
void finaloutput(int ant,double alpha,double beta,int iteration,int run,int *result,int bestrunresult,int *bestrunpath,double avg,double START,double END,int len);
#endif /* function_hpp */

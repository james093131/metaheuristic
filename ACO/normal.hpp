//
//  normal.hpp
//  test1
//
//  Created by TzuChieh on 2020/3/18.
//  Copyright © 2020 TzuChieh. All rights reserved.
//

#ifndef normal_hpp
#define normal_hpp
#include <stdio.h>
#include<iostream>
#include<fstream>
#include<sstream>
#include<stdlib.h>
#include <string.h>
#include<time.h>
#include<math.h>
// #define ant 51
// #define alpha 2.6
// #define beta 6.7
// #define iteration 1000
// #define run 30
#define dim 3//幾維
#define start 1
#define Q 0.9
#define decline 0.1
#define initial_pher 0.000167
using namespace std;
int* read(int &sum);//讀檔
void Print(int *arr,int len);//印出一維陣列
void PPrint(double *arr,int first,int second);
void makearr(int *arr,int *input,int len);//將測資讀為整理好的陣列
bool checkpathornot(int *arr,int loc,int len);//檢查是否有走過，走過為1沒走過為-1
#endif /* normal_hpp */

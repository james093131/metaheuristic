//
//  main.cpp
//  DE
//
//  Created by TzuChieh on 2020/07/29
//  Copyright © 2020 TzuChieh. All rights reserved.
//

#include "function.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    srand((unsigned int)time(NULL));
    int ITE = atoi(argv[1]);
    int POP = atoi(argv[2]);//幾組DE在RUN
    int iteration=1;
    double DE_POP[POP][dim];
    double DE_Vector[POP][dim-1];
    randomstart((double*)DE_POP,POP,dim);//隨機起始位置
    double globalbest[3]={0,0,100000};//當作最佳解的xyf(x)用
    int whereami=0;
    double temp=globalbest[2];
    Vector_make( (double*)DE_POP,(double*)DE_Vector,POP,dim);
    for(int i=0;i<POP;i++)
    {
        for(int j=0;j<dim-1;j++)
        {
            cout<<DE_Vector[i][j]<<' ';
        }
        cout<<endl;
    }

}

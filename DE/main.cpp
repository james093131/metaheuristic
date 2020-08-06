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
    int DIM = atoi(argv[3]);//幾組DE在RUN
    int iteration=0;
    double DE_POP[POP][DIM];
    double DE_Vector[POP][DIM-1];
    double best[DIM-1];
    double optimum=100000.00;
    int lowlow=-1;
    randomstart((double*)DE_POP,POP,DIM);//隨機起始位置
    Evaluation((double*)DE_POP,best,optimum,POP,DIM);
    cout<<optimum<<endl;
    while(iteration<ITE)
    {
        Vector_make((double*)DE_POP,(double*)DE_Vector,POP,DIM);
        select( (double*)DE_POP,(double*)DE_Vector,POP,DIM);
        Evaluation((double*)DE_POP,best,optimum,POP,DIM);
        cout<<"Iteration "<<iteration+1<<": "<<optimum<<endl;
        
        // for(int i=0;i<DIM-1;i++)
        // {
        //     cout<<best[i]<<' ';
        // }
        // cout<<endl;
        if(optimum<0.00001)
        {
            lowlow=1;
            break;
        }
        iteration++;
    }
    cout<<"---------------------------------------"<<endl;
    cout<<"Dimensions : "<<DIM<<endl;
    cout<<"Optimum : "<<optimum<<endl;
    cout<<"coordinate : "<<endl<<'(';
    for(int i=0;i<DIM-2;i++)
    {
        cout<<best[i]<<',';
    }
    cout<<best[DIM-2]<<')'<<endl;
    fstream file;//寫檔
    file.open("DE_Convergence.txt",ios::app);
    if(lowlow==1)
        file<<"The Iteration that Optimum is less than 0.00001 : "<<iteration<<endl;
    file<<"Dimensions : "<<DIM<<endl;
    file<<"Optimum : "<<optimum<<endl;
    file<<"coordinate : "<<endl<<'(';
    for(int i=0;i<DIM-2;i++)
    {
        file<<best[i]<<',';
    }
    file<<best[DIM-2]<<')'<<endl<<endl;
    
}

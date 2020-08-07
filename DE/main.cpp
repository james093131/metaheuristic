//
//  main.cpp
//  DE
//
//  Created by TzuChieh on 2020/08/07
//  Copyright © 2020 TzuChieh. All rights reserved.
//

#include "function.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    double START, END;
    srand((unsigned int)time(NULL));
    int ITE = atoi(argv[1]);//幾個Iteration
    int RUN = atoi(argv[2]);//幾個RUN
    int POP = atoi(argv[3]);//幾組DE在RUN
    int DIM = atoi(argv[4]);//幾組DE在RUN
    int r=0;
    double RUN_optimum=100000.00;
    double AVG_optimum=0;
    double AVG_Iteration=0;
    double RUN_best[DIM-1];//所有ＲＵＮ裡面最好解的座標
    double RUN_result[RUN];//儲存所有ＲＵＮ的結果

    // double Each_Iteration[ITE];
    // memset(Each_Iteration,0,sizeof(Each_Iteration));

    int lowlow;//測試程式在各維度的效果用的
    
    START = clock();
    while(r<RUN)
    {
        int iteration=0;
        double DE_POP[POP][DIM];
        double DE_Vector[POP][DIM-1];
        double ITE_best[DIM-1];
        double ITE_optimum=100000.00;
        lowlow=-1;//測試程式在各維度的效果用的
        randomstart((double*)DE_POP,POP,DIM);//隨機起始位置
        Evaluation((double*)DE_POP,ITE_best,ITE_optimum,POP,DIM);//衡量當前解，並儲存最優解
        while(iteration<ITE)
        {
            Vector_make((double*)DE_POP,(double*)DE_Vector,POP,DIM);//make u
            select( (double*)DE_POP,(double*)DE_Vector,POP,DIM);//crossover後，選擇子代or父代（較優的）
            Evaluation((double*)DE_POP,ITE_best,ITE_optimum,POP,DIM);
            //cout<<"Iteration "<<iteration+1<<": "<<ITE_optimum<<endl;
            //Each_Iteration[iteration]+=ITE_optimum;
            if(ITE_optimum<0.00001)
            {
                lowlow=1;
                break;
            }
            iteration++;
        }
        if(ITE_optimum < RUN_optimum)//記錄全部RUN的最佳解
        {
            RUN_optimum=ITE_optimum;
            for(int i=0;i<DIM-1;i++)
            {
                RUN_best[i]=ITE_best[i];
            }
        }
        AVG_optimum += ITE_optimum;
        AVG_Iteration += iteration;
        finaloutput( ITE_optimum, ITE_best, DIM, iteration, lowlow,r+1);
        r++;
    }
    END = clock();
    AVG_optimum = AVG_optimum/RUN;
    AVG_Iteration = AVG_Iteration/RUN;
    output_txt(RUN_optimum ,AVG_optimum,RUN_best,DIM,AVG_Iteration,ITE,lowlow,RUN,POP,START,END);

    // for(int i=0;i<ITE;i++)//製作收斂圖用
    // {
    //     Each_Iteration[i] = Each_Iteration[i]/RUN;
    // }
    // fstream file1;
    // file1.open("DE_Convergence.txt",ios::out);
    // for(int i=0;i<ITE;i++)
    // {
    //     file1 <<i+1<<' '<< Each_Iteration[i]<<endl;
    // }

}

//
//  main.cpp
//  ACOXCODE
//
//  Created by TzuChieh on 2020/3/18.
//  Copyright © 2020 TzuChieh. All rights reserved.
//

#include "normal.hpp"
#include "function.hpp"
int main(int argc, char const *argv[])
{
    int r = 0;
    int ant = atoi(argv[1]);
	double alpha = atof(argv[2]);
	double beta = atof(argv[3]);
    int iteration= atoi(argv[4]);
    int run= atoi(argv[5]);
    double START, END;
    srand(static_cast<unsigned int>(time(nullptr)));
    int *a;
    int templen;
    a = read(templen); //讀檔用的pointer

    int len = templen / dim;
    int bestrunpath[len + 1];
    int result[run];
    double iteration_optimum[1001];
    memset(iteration_optimum,0,sizeof(iteration_optimum));
    int bestrunresult = 100000;
    START = clock();

    int city[len][dim];
    double distancetable[len][len]; //儲存距離表
    makearr((int *)city, a, len);
    distancecal((double *)distancetable, (int *)city, len); //製作距離表
  
    //讀檔結束
    while (r < run)
    {
        double distance;
        double finaldistance = 1000000;
        double pher[len][len];                //紀錄費洛蒙表
        double phertemp[len][len];            //新增螞蟻的費洛蒙表等到該輪所有螞蟻走完後與上表進行衰退＆疊加
        phermoneinitial((double *)pher, len); //初始費洛蒙濃度
        //phermoneinitial((double *)phertemp, len); //初始費洛蒙濃度
        int path[len + 1];                    //儲存當前螞蟻的路徑
        int finalpath[len + 1];               //儲存到目前為止最好的路徑
        int iter = 1;
        int whichcycle = 0;
        while (iter < iteration)
        {
            //memset(phertemp, 0, sizeof(phertemp)); //新增一個費洛蒙表初始狀態為０
            double iter_bestdistance = 1000000;
            int iter_bestpath[len + 1];        
            //phermonermix((double *)phertemp, (double *)pher, len, len);
            for (int i = 0; i < ant; i++)
            {
                //int start=rand()%len+1;
                oneant((int *)city, (double *)pher, path, start, len, distance, (double *)distancetable,alpha,beta); //利用費洛蒙和距離公式計算出單隻螞蟻的路徑
                if (distance <= iter_bestdistance)
                { //儲存最佳解
                    iter_bestdistance = distance;
                    memcpy(iter_bestpath, path, sizeof(path));
                   // if (iter_bestdistance < 468)
                    //{
                    twoopt(iter_bestpath,len,iter_bestdistance,(double*)distancetable);
                    //}
                }
                //cout<<"ant "<<i+1<<" distance :"<<distance<<endl;//生成單一距離以及路徑
                distance = 0;
            }
            phermoneupdate(iter_bestpath, (double *)pher, iter_bestdistance, len, decline);
            //cout <<"Iteration "<<iter<< " best ant:" << iter_bestdistance << endl;
            if (iter_bestdistance < finaldistance)
                { //儲存最佳解
                    finaldistance = iter_bestdistance;
                    memcpy(finalpath, iter_bestpath, sizeof(iter_bestpath));
                    whichcycle = iter; //儲存最佳解來自第幾的ＩＴＥＲＡＴＩＯＮ
                    cout << "Iteration:" << iter << endl;
                    cout << "Current Optima:" << finaldistance << endl;
                }
            iteration_optimum[iter]+=finaldistance;
            //phermonermix((double *)pher, (double *)phertemp, len, len);
            bestphermoneupdate(finalpath, (double *)pher, finaldistance, len, decline);
            //Print(finalpath,len+1);//印出隨機產生的最佳解
            iter++;
        }
        cout << "Run :" << r + 1 << endl;
        cout << "Global Optimum:" << finaldistance << endl;
        cout << "The Global Optima is come from the " << whichcycle << " iteration" << endl;
        Print(finalpath, len + 1); //印出隨機產生的最佳解
        result[r] = finaldistance;
        if (result[r] < bestrunresult)
        {
            bestrunresult = result[r];
            memcpy(bestrunpath, finalpath, sizeof(finalpath));
        }
        r++;
    }
    END = clock();
    double avg = 0;
    for (int i = 0; i < run; i++)
    {
        avg += result[i];
    }
    avg = avg / run;

    cout << "---------------------------------" << endl;
    finaloutput(ant,alpha,beta,iteration,run,result,bestrunresult,bestrunpath,avg,START,END,len);
    
    fstream file;//寫檔
    file.open("ACOresult.txt",ios::app);
    file << endl;
    file << "alpha: " << alpha << endl;
    file << "beta: " << beta << endl;
    file << "numbers of ants: " << ant << endl;
    file << "numbers  of evaluations :" << iteration * ant << endl;
    file << "numbers of run :" << run << endl;
    file << "Best Optimum: " << bestrunresult << endl;
    file << "Best Optimum Path"<<endl;
    for(int i=0;i<len+1;i++)
    {
        file<<bestrunpath[i]<<' ';
    }
    file <<endl<< "Average Optimum : " << avg << endl;
    file << "Execution Time: " << (END - START) / CLOCKS_PER_SEC << "(s)" << endl;
    file.close();
    file.open("ACO_convergence.txt",ios::out);
    for(int i=1;i<iteration;i++)
    {
        file<<i<<' '<<(iteration_optimum[i]/run)<<endl;
    }
}

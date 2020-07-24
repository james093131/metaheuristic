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

    double START, END;
    srand(static_cast<unsigned int>(time(nullptr)));
    int *a;
    int templen;
    a = read(templen); //讀檔用的pointer

    int len = templen / dim;
    int bestrunpath[len + 1];
    int result[run];
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
        int path[len + 1];                    //儲存當前螞蟻的路徑
        int finalpath[len + 1];               //儲存到目前為止最好的路徑
        for (int i = 0; i < ant; i++)         //首次利用隨機的方式進行走訪
        {
            //int start=rand()%len+1;
            randompath((int *)city, distance, path, len, (double *)distancetable,start);
            //cout<<i<<'.'<<"Distance :"<<distance<<endl<<"Path:";
            //Print(path,len+1);
            phermoneupdate(path, (double *)pher, distance, len, decline);
            //cout<<endl;
            if (distance < finaldistance)
            {
                finaldistance = distance;
                memcpy(finalpath, path, sizeof(path));
            }
            distance = 0;
        } //螞蟻隨機亂爬，初始化完成
        int iter = 1;
        int whichcycle = 0;
        while (iter <= iteration)
        {
            memset(phertemp, 0, sizeof(phertemp)); //新增一個費洛蒙表初始狀態為０
            for (int i = 0; i < ant; i++)
            {
                //int start=rand()%len+1;
                oneant((int *)city, (double *)pher, path, start, len, distance, (double *)distancetable); //利用費洛蒙和距離公式計算出單隻螞蟻的路徑
                // if(distance<470)
                //     twoopt(path,len,distance,(double*)distancetable);
                // }
                if (distance <= finaldistance)
                { //儲存最佳解
                    finaldistance = distance;
                    memcpy(finalpath, path, sizeof(path));
                    whichcycle = iter; //儲存最佳解來自第幾的ＩＴＥＲＡＴＩＯＮ
                    if (finaldistance < 460)
                    {
                        // twoopt(path,len,finaldistance,(double*)distancetable);
                    }
                    cout << "Iteration:" << iter << endl;
                    cout << "Current Optima:" << finaldistance << endl;
                }
                phermoneupdate(path, (double *)phertemp, distance, len, decline);
                //cout<<"ant "<<i+1<<" distance :"<<distance<<endl;//生成單一距離以及路徑
                distance = 0;
            }

            phermonermix((double *)pher, (double *)phertemp, len, len);
            bestphermoneupdate(finalpath, (double *)pher, finaldistance, len, decline);
            //Print(finalpath,len+1);//印出隨機產生的最佳解
            iter++;
        }
        cout << "Run :" << r + 1 << endl;
        cout << "Global Optimum:" << finaldistance << endl;
        cout << "The Global Optima is come from the " << whichcycle << " iteration" << endl;
        ;
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
    int avg = 0;
    for (int i = 0; i < run; i++)
    {
        avg += result[i];
    }
    avg = avg / 30;

    cout << "---------------------------------" << endl;
    cout << "All run result :" << endl;
    Print(result, run);
    cout << "The Global Optimum Path : " << endl;
    Print(bestrunpath, len + 1); //印出隨機產生的最佳解
    cout << endl
         << "alpha: " << alpha << endl;
    cout << "beta: " << beta << endl;
    cout << "numbers of ants: " << ant << endl;
    cout << "numbers  of evaluations :" << iteration * ant << endl;
    cout << "numbers of run :" << run << endl;
    cout << "Best Optimum: " << bestrunresult << endl;
    cout << "Average Optimum : " << avg << endl;
    cout << "Execution Time: " << (END - START) / CLOCKS_PER_SEC << "(s)" << endl;
}

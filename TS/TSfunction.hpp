#define tabulistcoeff 0.05
#include <queue> 
#include "../normal/normal.hpp"
//cmd執行方式 ./TS 100(bit數)  1000(iteration) 20(run) 
void tabumake(queue<char> &,char *,int ,int );
int MemoryNeighborSelection(char *,int );
void NoneTabuNeighborSelection(char *,int ,queue<char>,int ,int &);
void TABU(char *,int ,queue<char>,int ,int &,int ,int ,int ,int *);
void RUN(char *,int ,queue<char>,int ,int &,int ,int ,int ,int *);

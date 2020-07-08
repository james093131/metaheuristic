#define randomnum_max 1
#define randomnum_min 0.5
#define A 0.95
#define temperature 1
#include "../normal/normal.hpp"
#include<math.h>
void NeighborSelection(char *,int );
double SAformula(int   ,int );
double randomminmax();
void update(double ,double ,char *,char *,int ,int &,int ,double &);

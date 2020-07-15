void sum(int *arr,int len,int &s)
{
    for(int i=0;i<len;i++)
    {
        s+=arr[i];
    }
}
void cut(int *value,float *split,int sum,int item)
{
    split[0]=0;split[item]=1;
    float temp=0;
    for(int i=1;i<item;i++)//設定區間用
    {
        temp+=value[i];
        split[i]=temp/sum;
    }
}
void tran(int &chc,float x,float *split,int len){
    for(int i=1;i<len;i++)
    {
        if(x>split[i-1]&&x<split[i])
        {

            chc=i-1;
            break;
        }
    }

}
void roulettechoose(int *arr,int *temp,int *value,int item,int len)
{
    int i=0;
    int s=0;
    int chc;
    float split[item+1];
    sum(value,len,s);
    cut(value,split,s,item);
    while(i<pop){
        float x = (float) rand() / (RAND_MAX + 1.0);
        tran(chc,x,split,pop+1);
        for(int k=0;k<len;k++)
        {
            *((int*)temp +len*i+k)=*((int*)arr +len*chc+k);
        }
        i++;
    }
}
void tournament(int *arr,int *temp,int *value,int item,int len){
    int i=0;
    while(i<item){
        int c1=rand()%(item);
        int c2=rand()%(item);
        int chc;
        if(value[c1]>value[c2]){
            chc=c1;
        }
        else{
            chc=c2;
        }
        for(int k=0;k<len;k++)
        {
        *((int*)temp +len*i+k)=*((int*)arr +len*chc+k);
        }
        i++;
    }
}
 
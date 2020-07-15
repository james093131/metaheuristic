void mutation(int *arr,int ind,int len)//隨機選取一點做調換
{
    int c=rand()%len;
    
        if( *((int*)arr +len*ind+c)==1)
            *((int*)arr +len*ind+c)=0;
        else
            *((int*)arr +len*ind+c)=1;
    
}
void crossover(int *arr,int *temp,int *best,int item,int len,float CR,float MR){//隨機生成一個切割點，將兩個染色體做交配
    int i=0;
    while(i<item){
        int c1=rand()%len;
        int c2=rand()%len;
        float t1 = (float) rand() / (RAND_MAX + 1.0);
        for(int k=0;k<len;k++)
        {
            if(t1<CR){
                if(k>c1)
                {
                *((int*)arr +len*i+k)=*((int*)temp +len*(i+1)+k);
                *((int*)arr +len*(i+1)+k)=*((int*)temp +len*(i)+k);
                }
                else{
                *((int*)arr +len*i+k)=*((int*)temp +len*(i)+k);
                *((int*)arr +len*(i+1)+k)=*((int*)temp +len*(i+1)+k);
                }
            }
            else{
                 *((int*)arr +len*i+k)=*((int*)temp +len*(i)+k);
                 *((int*)arr +len*(i+1)+k)=*((int*)temp +len*(i+1)+k);
            }
        }
        float x = (float) rand() / (RAND_MAX + 1.0);
        float y = (float) rand() / (RAND_MAX + 1.0);
        if(x<MR)
        {
        mutation(arr,i,len);
        }
        if(y<MR)
        {
        mutation(arr,i+1,len); 
        }
        i+=2;
    }


}

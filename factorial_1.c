#include<stdio.h>
int main()
{
    int arr_f[50];
    int t,s,temp=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d\n",&s);
        arr_f[0]=1;
        for(int i=1;i<=s;i++)
         {
           arr_f[i]=arr_f[i]*i+temp;
           temp=arr_f[i]/10;
         }
        for(int i=s;i<0;i--)
        {   if(arr_f[i]!=0)
            printf("%d",arr_f[i]);
        }
    
        
    
    
    }
    

}
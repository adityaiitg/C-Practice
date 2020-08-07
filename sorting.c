#include <stdio.h>

int main(void)
{
    int t;
    scanf("%d",&t);
    int arr[t];
    int j=t;
    while(t--)
    {
        scanf("%d",&arr[t-1]);
    }
    for(int i=0;i<j;i++)
    {
        for(int k=0;k<j-1;k++)
        if(arr[k]>arr[k+1])
        {
          int temp=arr[k];
          arr[k]=arr[k+1];
          arr[k+1]=arr[k];
        }
    }
	// your code goes here
	return 0;
}


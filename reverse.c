#include<stdio.h>
#include<stdlib.h>
int **solve(int A, int *len1, int *len2) {
int **arr;
int i,j;
*len1=A;
*len2=A;
arr=(int **)malloc(A*sizeof(int*));
for(i=0;i<A;i++){
    arr[i] = (int *)malloc((i+1)*sizeof(int)); 
     for(j=0;j<=i;j++){
     
        if(i==j||j==0){
            arr[i][j]=1;
        }
        if(i!=j&&j!=0) 
       arr[i][j]=arr[i-1][j-1]+arr[i-1][j];
        
    }   
}
return arr;
}


int main(){
    int a,b;
    int **c=solve(5,&a,&b);
    for(int i=0;i<20;i++){
        printf("%d",c[0][i]);
    }
}

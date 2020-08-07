#include<stdio.h>
void plot(void){
    int i,j;
  for(i=0;i<50;i++){
      printf("\n");
      for(j=0;j<150;j++)
      {   if(j-10!=i)
          {printf("*");}
          else
          {
            printf(" ");
          }
      }
      
  }
} 
int main(){
    plot();
}
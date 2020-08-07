#include<stdio.h> 
  

int search(int arr[], int n, int x) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
    { 
      
       if (arr[i] == x) 
         return i; 
    } 
  

    return -1; 
}  
  
int main() 
{ 
   
    int arr[100], x, t, n, i; 
  
    
    scanf("%d", &t);  
  
   
    while (t--) 
    { 
      
        scanf("%d", &n);  
  
       
        for (i=0; i<n; i++) 
           scanf("%d",&arr[i]); 
  
        
        scanf("%d", &x); 
  
        
        printf("%d\n", search(arr, n, x)); 
    } 
    return 0; 
} 

#include<bits/stdc++.h>
using namespace std;

void print(int **edges,int n,int sv,bool* visited){
     cout<<sv<<endl;
     visited[sv]=true;
     for(int i=0;i<n;i++){
         if(i==sv||visited[i]){
             continue;
         }
         if(edges[sv][i]==1){
             print(edges,n,i,visited);
         }
     }
}
int main(){
    int n;
    int e;
    cin>>n>>e;
    int** edges= new int*[n];
    for(int i=0;i<n;i++){
        edges[i]=new int[n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        edges[a][b]=1;
        edges[b][a]=1;
    }
    bool *visited=new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
print(edges,n,0,visited);
 
}
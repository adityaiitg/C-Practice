#include<bits/stdc++.h>
using namespace std;
void print(int ** edges,bool* visited,int V,int E,int start){
   visited[start]=true;
   cout<<start<<" ";
   for(int i=0;i<V;i++){
       if(visited[i]==false&&edges[start][i]==1){
          print(edges,visited,V,E,i);
       }
   }
   for(int i=0;i<V;i++){
       if(visited[i]==false){
           cout<<endl;
          print(edges,visited,V,E,i);
       }
}}
int main() {
    int V, E;
    cin >> V >> E;
    int** edges=new int*[V];
    for(int i=0;i<V;i++){
        edges[i]=new int[V];
        for(int j=0;j<V;j++){
            edges[i][j]=0;
        }
    }
    for(int i=0;i<E;i++){
        int a,b;
        cin>>a>>b;
        edges[a][b]=1;
        edges[b][a]=1;
    }
    bool* visited=new bool[V];
    for(int i=0;i<V;i++){
        visited[i]=false;
    }
    print(edges,visited,V,E,0);
  return 0;
}

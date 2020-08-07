#include<bits/stdc++.h>
using namespace std;
void dfs(int ** edges,bool* visited,int V,int E,int start){
   visited[start]=true;
   for(int i=0;i<V;i++){
       if(visited[i]==false&&edges[start][i]==1){
           dfs(edges,visited,V,E,i);
       }
   }
}
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
    dfs(edges,visited,V,E,0);
    int ans=0;   
    for(int i=0;i<V;i++){
        if(visited[i]==true){
            ans++;
        }
    }
    if(ans==V){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
  return 0;
}

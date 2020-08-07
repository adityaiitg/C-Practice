#include <bits/stdc++.h>
using namespace std;
void print(unordered_map<int,int> map,int tempX,int tempY){
  int curr=tempY;
  while(curr!=tempX){
      cout<<curr<<" ";
      curr=map[curr];
  }
  cout<<tempX;
}
void print_bfs(int V,int E,int tempX,int tempY,int **edges,bool *visited){
   unordered_map<int,int> map;
   queue<int> q;
   q.push(tempX);
   visited[tempX];
   while (q.empty()==false)
   {
        int front=q.front();
       for(int i=0;i<V;i++){
           if(edges[front][i]==1&&visited[i]==false){
               q.push(i);
               map.insert(make_pair(i,front));
               visited[i]=true;
               if(i==tempY){
                   print(map,tempX,tempY);
                   return;
               }
           }
       }
       q.pop();
   }
   return;
}

int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;
  int **edges=new int*[V];
    for(int i=0;i<V;i++){
        edges[i]=new int[V];
        for(int j=0;j<V;j++){
            edges[i][j]=0;
        }
    }
 for(int i=0;i<E;i++){
     int x,y;
     cin>>x>>y;
     edges[x][y]=1;
     edges[y][x]=1;
 }
  cin>>tempX>>tempY;
 bool* visited=new bool[V];
 for(int i=0;i<V;i++){
     visited[i]=false;
 }
print_bfs(V,E,tempX,tempY,edges,visited);
  return 0;
}
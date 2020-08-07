#include<bits/stdc++.h>
using namespace std;

/*
void print(int ** edges,int n,queue<int> *q,bool *visited){
    if(q->empty()){
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                q->push(i);
                print(edges,n,q,visited);
            }
            return;
        }
    }
    int s=q->front();
    cout<<s<<" ";
    for(int i=0;i<n;i++){
        if(edges[s][i]==1&&visited[i]==false)
        q->push(i);
    }
    
}
*/
void print(int ** edges,int n,bool *visited){
    int exit=0;
    queue<int> q;
    q.push(0);
    while (1){
      if(q.empty()){
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                q.push(i);
                cout<<endl;
                i=n;
            }
        }
        if(q.empty()){
            return;
        }}
      
      int s=q.front();
      if(visited[s]==false){
      cout<<s<<" ";
      for(int i=0;i<n;i++){
        if(edges[s][i]==1&&visited[i]==false)
          {q.push(i);}
      }
       visited[s]=true;
      }
      q.pop();
    }

}


int main(){
    int n;
    int e;
    cin>>n>>e;
    queue<int> q;
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
    print(edges,n,visited);
}
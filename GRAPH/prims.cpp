#include<bits/stdc++.h>
using namespace std;
int getMinVertex(bool* visited,int* weight,int n){
    int minVertex=-1;
    for(int i=0;i<n;i++){
        if(!visited[i]&&((minVertex==-1)||weight[minVertex]>weight[i])){
            minVertex=i;
        }
    }
    return minVertex;
}
void prims(int **edges,int n){
    bool* visited = new bool[n];
    int* parent= new int[n];
    int* weight= new int[n];
    for(int i=0;i<n;i++){
        weight[i]=INT_MAX;
    }
    parent[0]=-1;
    weight[0]=0;
    for(int i=0;i<n-1;i++){
        int minVertex=getMinVertex(visited,weight,n);
        visited[minVertex]=true;
        for(int j=0;j<n;j++){
            if(!visited[j]&&edges[minVertex][j]!=0){
                if(weight[j]>weight[minVertex]+edges[minVertex][j]){
                    weight[j]=weight[minVertex]+edges[minVertex][j];
                    parent[j]=minVertex;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        if(parent[i]<i){
            cout<<parent[i]<<" "<< i <<" "<<weight[i]<<endl;
        }else{
            cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
        }
    }
    delete [] parent;
    delete [] weight;
    delete [] visited;
}
int main(){
    int n;
    int e;
    cin>>n>>e;
    int **edges=new int*[n];
    for(int i=0;i<n;i++){
        edges[i]=new int[n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }
    for(int i=0;i<e;i++){
        int x,y,w;
        cin>>x>>y>>w;
        edges[x][y]=w;
        edges[y][x]=w;
    }
    cout<<endl;
    prims(edges,n);
    for(int i=0;i<n;i++){
        delete [] edges[i];
    }
    delete [] edges;
}
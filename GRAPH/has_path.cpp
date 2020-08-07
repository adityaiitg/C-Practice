#include<bits/stdc++.h>
using namespace std;
bool has_path(int ** edges,int n,int s,int e,bool *visited){
    if(edges[s][e]==1){
        return true;
    }
    bool ans=false;
    visited[s]=true;
    for(int i=0;i<n;i++){
        if(edges[s][i]&&visited[i]==false){
            visited[i]=false;
           ans=ans||has_path(edges,n,i,e,visited);
        }
    }
    return ans;
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
    int s1,e1;
    cin>>s1>>e1;
    bool* visited=new bool[n];
    if(has_path(edges,n,s1,e1,visited))
    {
    cout<<"true";
    }
    else{
    cout<<"fasle";
    }
    return 0;
}
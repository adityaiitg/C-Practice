#include<bits/stdc++.h>
using namespace std;
vector<int> has_path(int ** edges,int n,int s,int e,bool *visited){
    vector<int> v;
    if(edges[s][e]==1){
        v.push_back(e);
        v.push_back(s);
        return v;
    }
    visited[s]=true;
    for(int i=0;i<n;i++){
        if(edges[s][i]&&visited[i]==false){
            visited[i]=true;
            vector<int> v=has_path(edges,n,i,e,visited);
            if(v.size()>0){
              v.push_back(s);
              return v;
            }
        }
    }
    return v;
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
    vector<int> v=has_path(edges,n,s1,e1,visited);
        if(v.size()>0){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }}
    return 0;
}
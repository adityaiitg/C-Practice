#include<bits/stdc++.h>
using namespace std;
void buildtree(int *arr,int * tree,int start,int end,int treenode){
   if(start==end){
       tree[treenode]=arr[start];
       return;
   } 
   int mid=(start+end)/2;
   buildtree(arr,tree,start,mid,2*treenode);
   buildtree(arr,tree,mid+1,end,2*treenode+1);
   tree[treenode]=min(tree[2*treenode],tree[2*treenode+1]);
}
void updateSegmentTreeLazy(int* tree,int *lazy,int low,int high,int startR,int endR,int lazynode,int inc){
if(low>high){
    return;
}
if(lazy[lazynode]!=0){
    tree[lazynode]+=lazy[lazynode];
    if(low!=high){
     lazy[2*lazynode]+=lazy[lazynode];
     lazy[2*lazynode+1]+=lazy[lazynode];   
    }
    lazy[lazynode]=0;
}
if(startR>high||endR<low){
    return;
}
if(startR<=low&&endR>=high){
    tree[lazynode]+=inc;
    if(low!=high){
        lazy[2*lazynode]+=inc;
        lazy[2*lazynode+1]+=inc;
    }
    return;
}
int mid=(high+low)/2;
updateSegmentTreeLazy(tree,lazy,low,mid,startR,endR,2*lazynode,inc);
updateSegmentTreeLazy(tree,lazy,mid+1,high,startR,endR,2*lazynode+1,inc);
tree[lazynode]=min(tree[2*lazynode],tree[2*lazynode+1]);
}
int main(){
    int arr[]={1,3,-2,4};
    int* tree= new int[12]();
     buildtree(arr,tree,0,3,1);
    int *lazy=new int[12]();
    updateSegmentTreeLazy(tree,lazy,0,3,0,3,1,3);
    updateSegmentTreeLazy(tree,lazy,0,3,0,1,1,2);
    cout<<"Segment Tree"<<endl;
    for(int i=0;i<12;i++){
        cout<<tree[i]<<endl;
    }
    cout<<"Lazy Tree"<<endl;
    for(int i=0;i<12;i++){
        cout<<lazy[i]<<endl;
    }
    return 0;
}
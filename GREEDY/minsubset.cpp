#include<bits/stdc++.h>
using namespace std;
void make_segment_tree(long long *arr,long long start,long long end,long long *tree,long long idx){
    if(start==end){
        tree[idx]=arr[start];
        return;
    }
    long long mid=(start+end)/2;
    make_segment_tree(arr,start,mid,tree,2*idx);
    make_segment_tree(arr,mid+1,end,tree,2*idx+1);
    tree[idx]=min(tree[2*idx],tree[2*idx+1]);
}
long long min_element(long long* tree,long long start,long long end,long long ss,long long se,long long idx){
    if(ss<=start&&end<=se){
        return tree[idx];
    }
    if(se<start||end<ss){
        return INT_MAX;
    }
    long long mid=(start+end)/2;
    return min(min_element(tree,start,mid,ss,se,2*idx),min_element(tree,mid+1,end,ss,se,2*idx+1));
}
void update(long long* tree,long long start,long long end,long long idx,long long data,long long index){
    if(idx>end||idx<start){
        return;
    }
    if(start==end){
        if(start==idx){
            tree[index]=data;
        }
        return;
    }
    long long mid=(start+end)/2;
    if(mid>=index){
        update(tree,start,mid,idx,data,2*index);
    }
    else{
        update(tree,mid+1,end,idx,data,2*index+1);
    }
//    update(long long* tree,long long start,long long end,long long idx,long long data,long long index);
//    update(long long* tree,long long start,long long end,long long idx,long long data,long long index);
    tree[index]=min(tree[2*index],tree[2*index+1]);
}

int main() {
    long long t,n;
    cin>>n>>t;
    long long arr[n];
    for(long long i=0;i<n;i++){
        cin>>arr[i];
    }
    long long* tree=new long long[4*n];
    make_segment_tree(arr,0,n-1,tree,1);
    while(t--){
        char c;
        long long a,b;
        cin>>c>>a>>b;
        if(c=='q'){
            cout<<min_element(tree,0,n-1,a-1,b-1,1)<<endl;
        }
        if(c=='u'){
            update(tree,0,n-1,a-1,b,1);
        }
        
    }
    return 0;
	// Write your code here
}

/*

Minimum In SubArray
Send Feedback
Range Minimum Query
Given an array A of size N, there are two types of queries on this array.
1) q l r: In this query you need to print the minimum in the sub-array A[l:r].
2) u x y: In this query you need to update A[x]=y.
Input:
First line of the test case contains two integers, N and Q, size of array A and number of queries.
Second line contains N space separated integers, elements of A.
Next Q lines contain one of the two queries.
Output:
For each type 1 query, print the minimum element in the sub-array A[l:r].
Contraints:
1≤N,Q,y≤10^5
1≤l,r,x≤N
Sample Input :
5 5
1 5 2 4 3
q 1 5
q 1 3
q 3 5
u 3 6
q 1 5
Sample Output :
1
1
2
1
*/

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
    return;
}
long long min_element(long long* tree,long long start,long long end,long long ss,long long se,long long idx){
    if(se<start||end<ss){
        return INT_MAX;
    }
    if(ss<=start&&end<=se){
        return tree[idx];
    }
    long long mid=(start+end)/2;
    return min(min_element(tree,start,mid,ss,se,2*idx),min_element(tree,mid+1,end,ss,se,2*idx+1));
}
void update(long long* arr,long long* tree,long long start,long long end,long long idx,long long data,long long index){
    if(start==end){
            tree[index]=data;
            arr[idx]=data;
        return;
    }
    long long mid=(start+end)/2;
    if(mid>=idx){
        update(arr,tree,start,mid,idx,data,2*index);
    }
    else{
        update(arr,tree,mid+1,end,idx,data,2*index+1);
    }
    tree[index]=min(tree[2*index],tree[2*index+1]);
    return;
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
        else if(c=='u'){
            update(arr,tree,0,n-1,a-1,b,1);
        }
        
    }
    return 0;
	// Write your code here
}
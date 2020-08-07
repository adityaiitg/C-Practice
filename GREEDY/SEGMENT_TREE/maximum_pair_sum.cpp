/*
Maximum Pair Sum
Send Feedback
You are given a sequence A[1], A[2], ..., A[N], ( 0 ≤ A[i] ≤ 10^8 , 2 ≤ N ≤ 10^5 ). There are two types of operations and they are defined as follows:
Update:
This will be indicated in the input by a 'U' followed by space and then two integers i and x.
U i x, 1 ≤ i ≤ N, and x, 0 ≤ x ≤ 10^8.
This operation sets the value of A[i] to x.
Query:
This will be indicated in the input by a 'Q' followed by a single space and then two integers i and j.
Q x y, 1 ≤ x < y ≤ N.
You must find i and j such that x ≤ i, j ≤ y and i != j, such that the sum A[i]+A[j] is maximized. Print the sum A[i]+A[j].
Input
The first line of input consists of an integer N representing the length of the sequence. 
Next line consists of N space separated integers A[i]. Next line contains an integer Q, Q ≤ 10^5, representing the number of operations. Next Q lines contain the operations.
Output
 Output the maximum sum mentioned above, in a separate line, for each Query.
Input:
5
1 2 3 4 5
6
Q 2 4
Q 2 5
U 1 6
Q 1 5
U 1 7
Q 1 5
Output:
7
9
11
12


*/
#include<bits/stdc++.h>
using namespace std;
void make_segment_tree(long long *arr,long long start,long long end,pair<long long,long long>* tree,long long idx){
    if(start==end){
        tree[idx].first=arr[start];
        tree[idx].second=INT_MIN;
        return;
    }
    long long mid=(start+end)/2;
    make_segment_tree(arr,start,mid,tree,2*idx);
    make_segment_tree(arr,mid+1,end,tree,2*idx+1);
    long long temp[4];
    temp[0]=tree[2*idx].first;
    temp[1]=tree[2*idx].second;
    temp[2]=tree[2*idx+1].first;
    temp[3]=tree[2*idx+1].second;
    sort(temp,temp+4);
    tree[idx].first=temp[3];
    tree[idx].second=temp[2];
    return;
}
pair<long long,long long> min_element(pair<long long,long long>* tree,long long start,long long end,long long ss,long long se,long long idx){
    if(se<start||end<ss){
        return make_pair<long long,long long>(INT_MIN,INT_MIN);
    }
    if(ss<=start&&end<=se){
        return tree[idx];
    }
    long long mid=(start+end)/2;
    pair<long long,long long> p1=min_element(tree,start,mid,ss,se,2*idx);
    pair<long long,long long> p2=min_element(tree,mid+1,end,ss,se,2*idx+1);
    long long temp[4];
    temp[0]=p1.first;
    temp[1]=p1.second;
    temp[2]=p2.first;
    temp[3]=p2.second;
    sort(temp,temp+4);
    long long a=temp[3];
    long long b=temp[2];
   
    return make_pair(a,b);
  
}
void update(long long* arr,pair<long long,long long>* tree,long long start,long long end,long long idx,long long data,long long index){
    if(start==end){
            tree[index].first=data;
            tree[index].second=INT_MIN;
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
    long long temp[4];
    temp[0]=tree[2*index].first;
    temp[1]=tree[2*index].second;
    temp[2]=tree[2*index+1].first;
    temp[3]=tree[2*index+1].second;
    sort(temp,temp+4);
    tree[index].first=temp[3];
    tree[index].second=temp[2];
    return;
}
int main() {
    long long t,n;
    cin>>n;
    long long arr[n];
    for(long long i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>t;
    pair<long long,long long>* tree=new pair<long long,long long>[4*n];
    make_segment_tree(arr,0,n-1,tree,1);
    while(t--){
        char c;
        long long a,b;
        cin>>c>>a>>b;
        if(c=='Q'){
            pair<long long,long long> p1=min_element(tree,0,n-1,a-1,b-1,1);
            cout<<p1.first+p1.second<<endl;
        }
        else if(c=='U'){
            update(arr,tree,0,n-1,a-1,b,1);
        }
        
    }
    return 0;
	// Write your code here
}
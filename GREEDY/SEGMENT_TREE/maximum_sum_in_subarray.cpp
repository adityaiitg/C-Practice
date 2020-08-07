/*
Maximum Sum In Subarray
Send Feedback
You are given a sequence A[1], A[2], ..., A[N] . ( |A[i]| ≤ 15007 , 1 ≤ N ≤ 50000 ). A query is defined as follows:
Query(x,y) = Max { a[i]+a[i+1]+...+a[j] ; x ≤ i ≤ j ≤ y }.
Given M queries, your program must output the results of these queries.
Input
The first line of the input file contains the integer N.
In the second line, N numbers follow.
The third line contains the integer M.
M lines follow, where line i contains 2 numbers xi and yi.
Output
Your program should output the results of the M queries, one 
query per line.
Sample Input:
3 
-1 2 3 
1
1 2
Sample Output:
2

*/
#include<bits/stdc++.h>
using namespace std;
#define node treenode
#define ll long long
typedef struct treenode{
	ll maxsum;
	ll sum;
	ll bps;
	ll bss; 
} treenode;
void buildtree(ll *arr,treenode* tree,int start,int end,int curr_node){
  if(start==end){
	  tree[curr_node].maxsum=arr[start];
	  tree[curr_node].sum=arr[start];
	  tree[curr_node].bps=arr[start];
	  tree[curr_node].bss=arr[start];
	  return;
  }
  int mid=(start+end)/2;
  buildtree(arr,tree,start,mid,2*curr_node);
  buildtree(arr,tree,mid+1,end,2*curr_node+1);
  treenode left=tree[2*curr_node];
  treenode right=tree[2*curr_node+1];
  tree[curr_node].maxsum=max(left.maxsum,max(right.maxsum,max(left.sum+right.sum,max(left.sum+right.bps,max(right.sum+left.bss,right.bps+left.bss)))));
  tree[curr_node].sum=left.sum+right.sum;
  tree[curr_node].bps=max(left.bps,right.bps+left.sum);
  tree[curr_node].bss=max(right.bss,right.sum+left.bss);
  return;
}
ll treesubsetsum(treenode* tree,int start,int end,int left,int right,int curr_node){
    // NO INTERSECTION
	if(start>right||end<left){
		return INT_MIN;
	}
	// fully inside
	if(left<=start&&end<=right){
        return tree[curr_node].maxsum;
	}
	int mid=(start+end)/2;
	return (treesubsetsum(tree,start,mid,left,right,2*curr_node)+treesubsetsum(tree,mid+1,end,left,right,2*curr_node+1));
}
node query(node* tree, int start, int end, int treeNode, int left, int right){
	
	//Completely out
	if (left>end || right<start)
	{
		node temp;
		temp.maxsum = INT_MIN;
		temp.bss = INT_MIN;
		temp.bps = INT_MIN;
		temp.sum = INT_MIN;
		return temp;
	}

	//Completely inside
	if (start>=left && end<=right)
	{
		return tree[treeNode];
	}

	//Partially inside
	
	int mid = (start+end)/2;

	if(left>mid){
		return query(tree, mid+1, end, 2*treeNode+1, left, right);
	}

	if(right<=mid){
		return query(tree, start, mid, 2*treeNode, left, right);
	}

	node l = query(tree, start, mid, 2*treeNode, left, right);
	node r = query(tree, mid+1, end, 2*treeNode+1, left, right);

	node result;

	result.sum = l.sum+r.sum;
	result.bps = max(l.bps, l.sum+r.bps);
	result.bss = max(r.bss, r.sum+l.bss);
	result.maxsum = max(result.bps, 
					max(result.bss,
					max(l.maxsum,max(r.maxsum,
					l.bss+r.bps))));

	return result;
	

}


int main() {
	int n;
	cin>>n;
	ll* arr=new ll[n*3];
    treenode* tree=new treenode[4*n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
    buildtree(arr,tree,0,n-1,1);
	int m;
	cin>>m;
	while (m--)
	{
			ll xi,yi;;
			cin>>xi>>yi;
		cout<<query(tree,0,n-1,1,xi-1,yi-1).maxsum<<endl;
	}
}
/*
Horrible Queries
Send Feedback
World is getting more evil and it's getting tougher to get into the Evil League of Evil.
Since the legendary Bad Horse has retired, now you have to correctly answer the evil questions of Dr. Horrible
, who has a PhD in horribleness (but not in Computer Science). 
You are given an array of N elements, which are initially all 0. 
After that you will be given C commands. They are -
0 p q v - you have to add v to all numbers in the range of p to q (inclusive), 
where p and q are two indexes of the array.
1 p q - output a line containing a single integer which is the sum of all the array elements between p and q (inclusive)
Input
In the first line you'll be given T, number of test cases.

Each test case will start with N (N <= 100 000) and C (C <= 100 000). After that you'll be given C commands in the format as mentioned above. 1 <= p, q <= N and 1 <= v <= 10^7.
Output
Print the answers of the queries.
Input:
1
8 6
0 2 4 26
0 4 8 80
0 4 5 20
1 8 8 
0 5 7 14
1 4 8
Output:
80  
508


*/
#define ll long long
#include<bits/stdc++.h>
using namespace std;
void updateSegmentTreeLazy(ll* tree,ll *lazy,int low,int high,int startR,int endR,int lazynode,ll inc){
if(low>high){
    return;
}
if(lazy[lazynode]!=0){
    tree[lazynode]+=lazy[lazynode]*(high-low+1);
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
    tree[lazynode]+=inc*(high-low+1);
    if(low!=high){
        lazy[2*lazynode]+=inc;
        lazy[2*lazynode+1]+=inc;
    }
    return;
}
int mid=(high+low)/2;
updateSegmentTreeLazy(tree,lazy,low,mid,startR,endR,2*lazynode,inc);
updateSegmentTreeLazy(tree,lazy,mid+1,high,startR,endR,2*lazynode+1,inc);
tree[lazynode]=tree[2*lazynode]+tree[2*lazynode+1];
}
ll query(ll* tree,ll *lazy,int low,int high,int startR,int endR,int lazynode){
if(low>high){
    return 0;
}
if(lazy[lazynode]!=0){
    tree[lazynode]+=lazy[lazynode]*(high-low+1);
    if(low!=high){
     lazy[2*lazynode]+=lazy[lazynode];
     lazy[2*lazynode+1]+=lazy[lazynode];   
    }
    lazy[lazynode]=0;
}
if(startR>high||endR<low){
    return 0;
}
if(startR<=low&&endR>=high){
    return tree[lazynode];
}
int mid=(high+low)/2;
ll ans1=query(tree,lazy,low,mid,startR,endR,2*lazynode);
ll ans2=query(tree,lazy,mid+1,high,startR,endR,2*lazynode+1);
ll ans=ans1+ans2;
return ans;
}
int main() {
	int k;
	cin>>k;
	while(k--){
    int n,t;
	cin>>n>>t;
	ll tree[4*n]={0};
	ll lazy[4*n]={0};
    while(t--){
		int c;
		cin>>c;
		if(c==0){
			int p,q;
			ll v;
			cin>>p>>q>>v;
		   updateSegmentTreeLazy(tree,lazy,0,n-1,p-1,q-1,1,v);
		}
		if(c==1){
			int p,q;
			cin>>p>>q;	
          cout<<query(tree,lazy,0,n-1,p-1,q-1,1)<<endl;
		}
	}
	}
}
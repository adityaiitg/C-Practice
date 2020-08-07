/*Vasya vs Rhezo
Send Feedback
Queen Vasya is preparing for a war against Rhezo. She has N warriors in total arranged in a line.
 Let us number the warriors by numbers from 1 to N. She will fight Rhezo's army for Q days, and each day she can choose only one warrior.
For each warrior, we know 2 values associated with him, let us call these A and B. 
Each day Vasya can choose her warrior from a range Li to Ri, she must choose the warrior with maximum A value. 
If there is more than 1 warrior having the same maximum A value, she chooses the warrior with minimum B value. 
If still there is more than 1 warrior with same maximum A value and same minimum B value, she chooses the one with lower index in line.
You being the hand of Queen Vasya, need to help her in choosing the warrior for each day.
Input:
First line contains a single integer N, denoting the number of warriors Queen Vasya has. 
Second line contains N space separated integers Ai. Third line contains N space separated integers Bi.
Next line contains a single integer Q, denoting the number of days Queen Vasya chooses a warrior. 
Each of the next Q lines contains 2 integers Li and Ri.
Output:
For each Li and Ri, print the index of the warrior that Queen Vasya should choose.
Constraints:
1≤ N,Q ≤10^6
1≤ Ai,Bi ≤10^9
1≤Li≤Ri
Sample Input
5
1 8 4 6 8
4 8 6 3 7
4
1 4
2 4
3 4
1 5
Sample Output
2
2
4
5
*/
#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
	int index;
	int a;
	int b;
	/* data */
} node;

void built_tree(int start,int end,pair<int,int> *arr,node* tree,int treenode){
	if(start==end){
		tree[treenode].index=start;
		tree[treenode].a=arr[start].first;
		tree[treenode].b=arr[start].second;
		return;
	}
	int mid=(start+end)/2;
	built_tree(start,mid,arr,tree,2*treenode);
	built_tree(mid+1,end,arr,tree,2*treenode+1);
	if(tree[2*treenode].a==tree[2*treenode+1].a){
		if(tree[2*treenode].b<=tree[2*treenode+1].b){
           tree[treenode].index=tree[2*treenode].index;
		   tree[treenode].a=tree[2*treenode].a;
		   tree[treenode].b=tree[2*treenode].b;
		}
		else{
            tree[treenode].index=tree[2*treenode+1].index;
		   tree[treenode].a=tree[2*treenode+1].a;
		   tree[treenode].b=tree[2*treenode+1].b;
		}
	}
	else if(tree[2*treenode].a<tree[2*treenode+1].a){
		   tree[treenode].index=tree[2*treenode+1].index;
		   tree[treenode].a=tree[2*treenode+1].a;
		   tree[treenode].b=tree[2*treenode+1].b;
	}
	else {
		tree[treenode].index=tree[2*treenode].index;
		   tree[treenode].a=tree[2*treenode].a;
		   tree[treenode].b=tree[2*treenode].b;
	}

}
node query(int start,int end,int left,int right,node* tree,int treenode){
	if(left>end||right<start){
		node n;
		n.index=-1;
		n.a=0;
		n.b=0;
		return n;
	}
	if(left<=start&&right>=end){
		return tree[treenode];
	}
	int mid=(start+end)/2;
	node ans1=query(start,mid,left,right,tree,2*treenode);
	node ans2=query(mid+1,end,left,right,tree,2*treenode+1);
	if(ans1.index!=-1&&ans2.index!=-1){
		if(ans1.a==ans2.a){
           if(ans1.b<=ans2.b){
			   return ans1;
		   }
		   else{
			   return ans2;
		   }
		}
		else if(ans1.a>ans2.a){
            return ans1;
		}
		else{
			return ans2;
		}
	}
	if(ans1.index==-1)
		return ans2;
		return ans1;
}
int main() {
    int n;
	cin>>n;
	pair<int,int> arr[n];
	for(int i=0;i<n;i++)
	    cin>>arr[i].first;
	for(int i=0;i<n;i++)
	    cin>>arr[i].second;
	node tree[4*n];
	 built_tree(0,n-1,arr,tree,1); 
	 int q;
	 cin>>q;
	 while (q--)
	 {
		 int x,y;
		 cin>>x>>y;
		  cout<<1+query(0,n-1,x-1,y-1,tree,1).index<<endl;
		 /* code */
	 }

}

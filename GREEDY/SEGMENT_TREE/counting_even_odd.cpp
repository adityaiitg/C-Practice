/*
Counting Even/Odd
Send Feedback
Ashu and Shanu are best buddies. One day Shanu gives Ashu a problem to test his intelligence.He gives him an array of N natural numbers and asks him to solve the following queries:-
Query 0 :- modify the element present at index i to x.
Query 1:- count the number of even numbers in range l to r inclusive.
Query 2:- count the number of odd numbers in range l to r inclusive.
Input:
First line of the input contains the number N. Next line contains N natural numbers. 
Next line contains an integer Q followed by Q queries.

0 x y - modify the number at index x to y. 

1 x y - count the number of even numbers in range l to r inclusive.

2 x y - count the number of odd numbers in range l to r inclusive.
Constraints:
1<=N,Q<=10^5

1<=l<=r<=N 

0<=Ai<=10^9

1<=x<=N

0<=y<=10^9
Note:-
indexing starts from 1.
Sample Input
6
1 2 3 4 5 6
4
1 2 5
2 1 4
0 5 4
1 1 6
Sample Output
2
2
4
*/
#include<bits/stdc++.h>
using namespace std;
//even is first odd is second
void built_tree(int start,int end,int* arr,pair<int,int>* tree,int treenode){
   if(start==end){
       if(arr[start]%2==1){
           tree[treenode].first=0;
           tree[treenode].second=1;
       }
       else{
           tree[treenode].first=1;
           tree[treenode].second=0;
       }
       return;
   }
   int mid=(start+end)/2;
   built_tree(start,mid,arr,tree,2*treenode);
   built_tree(mid+1,end,arr,tree,2*treenode+1);
   tree[treenode].first=tree[2*treenode].first+tree[2*treenode+1].first;
   tree[treenode].second=tree[2*treenode].second+tree[2*treenode+1].second;
   return;
}
void modify(int start,int end,int *arr,pair<int,int>*tree,int treenode,int position,int element){
    if(end==start){
        arr[start]=element;
       if(arr[start]%2==1){
           tree[treenode].first=0;
           tree[treenode].second=1;
       }
       else{
           tree[treenode].first=1;
           tree[treenode].second=0;
       } 
        return;
    }
    int mid=(start+end)/2;
    if(mid<=position){
        modify(start,mid,arr,tree,2*treenode,position,element);
    }
    else{
        modify(mid+1,end,arr,tree,2*treenode+1,position,element);
    }
        tree[treenode].first=tree[2*treenode].first+tree[2*treenode+1].first;
        tree[treenode].second=tree[2*treenode].second+tree[2*treenode+1].second;
        return;

}
int count_odd(int start,int end,int l,int r,int *arr,pair<int,int>*tree,int treenode){
    //fully outside
    if(r<start||end<l){
        return 0;
    }
    //fully inside
    if(start<=l&&end>=r){
      return tree[treenode].second;
    }
    //partial
    int mid=(start+end)/2;
    int ans1=count_odd(start,mid,l,r,arr,tree,2*treenode);
    int ans2=count_odd(mid+1,end,l,r,arr,tree,2*treenode+1);
    return ans1+ans2;
}
int count_even(int start,int end,int l,int r,int *arr,pair<int,int>*tree,int treenode){
     //fully outside
    if(r<start||end<l){
        return 0;
    }
    //fully inside
    if(start<=l&&end>=r){
      return tree[treenode].first;
    }
    //partial
    int mid=(start+end)/2;
    int ans1=count_even(start,mid,l,r,arr,tree,2*treenode);
    int ans2=count_even(mid+1,end,l,r,arr,tree,2*treenode+1);
    return (ans1+ans2);
}
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
      {  cin>>arr[i];}
    pair<int,int> tree[4*n];
    built_tree(0,n-1,arr,tree,1);
    int q;
    cin>>q;
    while(q--){
        char query;
        int x,y;
        cin>>query>>x>>y;
        switch(query)
        {
        case '0':modify(0,n-1,arr,tree,1,x-1,y);
            break;
        case '1': 
        cout<<count_even(0,n-1,x-1,y-1,arr,tree,1)-1<<endl;
            break;
        case '2':
         cout<<count_odd(0,n-1,x-1,y-1,arr,tree,1)<<endl;
            break;
        default:
            break;
        }
    }
}
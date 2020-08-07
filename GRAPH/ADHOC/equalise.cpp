#include<bits/stdc++.h>
using namespace std;
int main(){
    int size;
    cin>>size;
    string s,t;
    int ans=0;
    cin>>s>>t;
    for(int i=0;i<size-1;i++){
        if(s[i]!=t[i]){
            if(i+1<size&&s[i+1]!=s[i]&&s[i]!=t[i+1]){
                 i++;
            }
            ans++;
        }
    }

    cout<<ans;
}
#include<bits/stdc++.h>
using namespace std;
string lps(string s){
    int n=s.length();
    int start=1;
    int end=0;
    for(int i=0;i<n;i++){
        int l=i;
        int r=i;
        while (l>=0&&r<n&&(s[l]==s[r])){
            if(end-start<(r-l)){
                start=l;
                end=r;
            }
            l--;
            r++;
        }
        l=i;
        r=i+1;
        while (l>=0&&r<n&&(s[l]==s[r])){
            if(end-start<(r-l)){
                start=l;
                end=r;
            }
            l--;
            r++;
        }
    }
    return s.substr(start,end-start+1);
}
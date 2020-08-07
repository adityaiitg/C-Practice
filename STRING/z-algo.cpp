#include<bits/stdc++.h>
using namespace std;
void buildZ(int *z,string str){
    int l=0;
    int r=0;
    int n=str.length();
    for(int i=1;i<n;i++){
        if(i>r){
            // i does not lie between l and r
            // z for this doesnt exist
        l=i;
        r=i;
        while (r<n&&str[r-l]==str[r]){ 
            r++;
        }
        z[i]=r-l;
        r--;
    }else{
        int k=i-l;
        if(z[k]<=r-i){
            // i lies between l and r
            // z will exist previously
            z[i]=z[k];
        }else{
            //Some part of Z is already included 
            // you have to strt matching further
            l=i;
            while (r<n&&str[r-l]==str[r]){
                r++;
            }
            z[i]=r-l;
            r--;
        }
    }
    }
}
void searchString(string text,string pattern){
    string str=pattern+"$"+text;
    int n=str.length();
    int *Z=new int[n]();
    buildZ(Z,str);
    for(int i=0;i<n;i++){
        if(Z[i]==pattern.length()){
            cout<<i-pattern.length()-1<<endl;
        }
    }


}
int main(){
    string text="abcdsafbcdfasbcda";
    string pattern="bcd";
    searchString(text,pattern);
    return 0;
}
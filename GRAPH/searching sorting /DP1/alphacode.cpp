 #include <bits/stdc++.h>
 #define mod 1000000007
using namespace std;
int ways(string digits, int n) 
{ 
    long long count[n+1];  
    count[0] = 1; 
    count[1] = 1; 
    if(digits[0]=='0')   
         return 0; 
    for (int i = 2; i <= n; i++) 
    { 
        count[i] = 0; 
        if (digits[i-1] > '0') 
            count[i] = count[i-1]%mod;  
        if (digits[i-2] == '1' ||  
              (digits[i-2] == '2' && digits[i-1] < '7') ) 
            count[i] += count[i-2]%mod; 
    } 
    return count[n]; 
} 
int main()
{    int a;
     string s;
        cin>>s;
        a=s[0]-'0';
    while(a!=0){
        cout<<ways(s,s.size())<<endl;
        s.clear();
        cin>>s;
        a=s[0]-'0';
    }
    return 0;
}


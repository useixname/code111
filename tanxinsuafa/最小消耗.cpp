/*
6
3 1 1 1
100
5 10 100 1
01010
5 10 1 1
11111
5 1 10 1
11111
12 2 1 10
101110110101
2 100 1 10
00
*/

#include<bits/stdc++.h>
using namespace std;

int t,n,a,b,c;
string s;
int chk(string s,int n,int a,int b,int c){
    int ans=0;
    if(a<b&&(a+c)<b){
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                ans+=(a+c);
            }
            else{
                ans+=a;
            }
        }
    }
    else if(a>b&&(b+c)<a){
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                ans+=(b+c);
            }
            else{
                ans+=b;
            }
        }
    }
    else{
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                ans+=a;
            }
            else{
                ans+=b;
            }
        }
    }
    return ans;
}
int main(){
    cin>>t;
    while(t--){
        cin>>n>>a>>b>>c>>s;
        cout<<chk(s,n,a,b,c)<<endl;
    }
}

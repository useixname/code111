#include<bits/stdc++.h>
using namespace std;
const int N=55;
string s1,s2;
int a[N],b[N],c[N];

void cheng(string s1,string s2){
    int n=s1.length(),m=s2.length();
    int len=n+m-1;
    for(int i=n;i>=1;i--){
        a[i]=s1[n-i]-'0';
    }
    for(int i=m;i>=1;i--){
        b[i]=s2[m-i]-'0';
    }
    int w=0,flag=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            c[i+j-1]+=(a[i]*b[j]);
            if(i==n&&j==m){
                if(c[i+j-1]>=10){
                    w=c[i+j-1]/10;
                    flag=1;
                }
            }
            c[i+j]+=c[i+j-1]/10;
            c[i+j-1]%=10;
        }
    }
    if(flag==1){
        c[len+1]=w;
    }
    for(int i=len+flag;i>=1;i--){
        cout<<c[i];
    }
}

int main(){
    cin>>s1>>s2;
    cheng(s1,s2);
    return 0;
}
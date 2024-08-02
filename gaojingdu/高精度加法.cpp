#include<bits/stdc++.h>
using namespace std;
const int N=55;
string s1,s2;
int a[N],b[N],c[N];

void jia(string s1,string s2){
    int n=s1.length(),m=s2.length();
    int len=max(n,m);
    for(int i=n;i>=1;i--){
        a[i]=s1[n-i]-'0';
    }
    for(int i=m;i>=1;i--){
        b[i]=s2[m-i]-'0';
    }
    int w=0,flag=0;
    for(int i=1;i<=len;i++){
        c[i]=(a[i]+b[i])+w;
        if(i==len&&c[i]>=10){
            flag=1;
        }
        w=c[i]/10;
        c[i]%=10;
    }
    if(flag==1){
        c[len+1]=1;
    }
    for(int i=len+flag;i>=1;i--){
        cout<<c[i];
    }
}

int main(){
    cin>>s1>>s2;
    jia(s1,s2);
    return 0;
}
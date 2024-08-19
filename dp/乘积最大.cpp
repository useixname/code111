#include<bits/stdc++.h>
using namespace std;
int a[65],b[65],c[65];
string sx;
string s[65];
string sum1[65],sum2[65];
int n,k;

string cheng(string s1,string s2){
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    int len1=s1.size(),len2=s2.size();
    for(int i=0;i<len1;i++){
        a[i]=s1[len1-1-i]-'0';
    }
    for(int i=0;i<len2;i++){
        b[i]=s2[len2-1-i]-'0';
    }
    for(int i=0;i<len1;i++){
        for(int j=0;j<len2;j++){
            c[i+j]+=a[i]*b[j];
            c[i+j+1]+=c[i+j]/10;
            c[i+j]%=10;
        }
    }
    int len=len1+len2-1;
    while(c[len]==0&&len>0){
        len--;
    }
    string s;
    for(int i=len;i>=0;i--){
        s+=to_string(c[i]);
    }
    return s;
}

string jia(string s1,string s2){
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    int len1=s1.size(),len2=s2.size();
    int len=max(len1,len2);
    for(int i=0;i<len1;i++){
        a[i]=s1[len1-1-i]-'0';
    }
    for(int i=0;i<len2;i++){
        b[i]=s2[len2-1-i]-'0';
    }
    for(int i=0;i<len;i++){
        c[i]+=a[i]+b[i];
        c[i+1]+=c[i]/10;
        c[i]%=10;
    }
    while(c[len]==0&&len>0){
        len--;
    }
    string s;
    for(int i=len;i>=0;i--){
        s+=to_string(c[i]);
    }
    return s;
}
int main(){
    cin>>n>>k;
    sum1[0]='1';
    sum2[0]='0';
    cin>>sx;
    for(int i=1;i<=n;i++){
        s[i]=sx[i-1];
        sum1[i]=cheng(sum1[i-1],s[i]);
        sum2[i]=jia(sum2[i-1],s[i]);
        cout<<sum1[i]<<" ";
        cout<<sum2[i]<<" ";
    }
    return 0;
}
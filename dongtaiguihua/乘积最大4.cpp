#include<bits/stdc++.h>
using namespace std;

struct node{
    int l=0;
    int w[65]={0};
}dp[65][10];
int a[65];
int n,m;
string s;

node mul(node x,node y){
    node ret;
    int len=x.l+y.l;
    for(int i=1;i<=x.l;i++){
        for(int j=1;j<=y.l;j++){
            ret.w[i+j-1]+=x.w[i]*y.w[j];
            ret.w[i+j]+=ret.w[i+j-1]/10;
            ret.w[i+j-1]%=10;
        }
    }
    while(ret.w[len]==0&&len>1){
        len--;
    }
    ret.l=len;
    return ret;
}

node cul(int l,int r){
    node ret;
    int len=r-l+1;
    ret.l=len;
    for(int i=1;i<=len;i++){
        ret.w[i]=a[r-i+1];
    }
    return ret;
}

node Max(node x,node y){
    if(!x.l||x.l<y.l){
        return y;
    }
    if(!y.l||x.l>y.l){
        return x;
    }
    for(int i=x.l;i>=1;i--){
        if(x.w[i]>y.w[i]){
            return x;
        }
        if(x.w[i]<y.w[i]){
            return y;
        }
    }
    return x;
}

int main(){
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        a[i]=s[i-1]-'0';
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j>=1;j--){
            dp[i][0].w[++dp[i][0].l]=a[j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int k=1;k<=min(m,i-1);k++){
            for(int j=k;j<i;j++){
                dp[i][k]=Max(dp[i][k],mul(dp[j][k-1],cul(j+1,i)));
            }
        }
    }
    for(int i=dp[n][m].l;i>=1;i--){
        cout<<dp[n][m].w[i];
    }
    return 0;
}
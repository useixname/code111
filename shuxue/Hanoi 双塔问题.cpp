#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=210;
int a[N],b[N],t[N];
int n;

void add(int b[],int a[]){
    int w=0;
    for(int i=1;i<=N;i++){
        b[i]=b[i]+a[i]+w;
        w=b[i]/10;
        b[i]%=10;
    }
}

void mul(int b[],int c){
    int w=0;
    for(int i=1;i<=N;i++){
        b[i]=b[i]*c+w;
        w=b[i]/10;
        b[i]%=10;
    }
}
signed main(){   
    ios_base::sync_with_stdio(0);
    cin>>n;
    a[1]=2;b[1]=2;
    for(int i=2;i<=n;i++){
        // memcpy(t,b,sizeof(b));
        mul(b,2);
        add(b,a);
        // memcpy(a,t,sizeof(b));
    }
    bool flag=0;
    for(int i=N;i>=1;i--){
        if(b[i]!=0) flag=1;
        if(flag) cout<<b[i];
    }
    return 0;
}
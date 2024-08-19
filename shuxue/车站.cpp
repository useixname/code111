#include<bits/stdc++.h>
using namespace std;
int f1[25],f2[25];
int a,n,m,x,ans;

bool chk(int x){
    int tot=0;
    f1[1]=a;f1[2]=x;
    f2[1]=0;f2[2]=x;
    for(int i=3;i<=n-1;i++){
        f2[i]=f1[i-1];
        f1[i]=f1[i-1]+f1[i-2];
    }
    for(int i=1;i<=n-1;i++){
        tot+=f1[i]-f2[i];
    }
    return tot<=m;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>a>>n>>m>>x;
    int l=0,r=2e4+1;
    while(l+1<r){
        int mid=l+r>>1;
        if(chk(mid)) l=mid;
        else r=mid;
    }
    f1[1]=a;f1[2]=l;
    f2[1]=0;f2[2]=l;
    for(int i=3;i<=x;i++){
        f2[i]=f1[i-1];
        f1[i]=f1[i-1]+f1[i-2];
    }
    for(int i=1;i<=x;i++){
        ans+=f1[i]-f2[i];
    }
    cout<<ans;
    return 0;
}
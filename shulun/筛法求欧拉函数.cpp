#include<bits/stdc++.h>
using namespace std;
const int N=1e8+10;
long long n,vis[N],p[N],phi[N],cnt=0,ans=0;

void get_phi(int n){
    phi[1]=1;
    for(int i=2;i<=n;i++){
        if(!vis[i]){
            p[++cnt]=i;
            phi[i]=i-1;
        }
        for(int j=1;p[j]*i<=n;j++){
            int m=p[j]*i;
            vis[m]=1;
            if(i%p[j]==0){
                phi[m]=p[j]*phi[i];
                break;
            }
            else{
                phi[m]=(p[j]-1)*phi[i];
            }
        }
    }
}

int main(){
    cin>>n;
    get_phi(n);
    for(int i=1;i<=n;i++){
        phi[i]+=phi[i-1];
    }
    for(int i=1;i<=cnt;i++){
        ans+=(phi[n/p[i]]*2)-1;
    }
    cout<<ans;
    return 0;
}
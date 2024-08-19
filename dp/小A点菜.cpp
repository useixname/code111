#include<bits/stdc++.h>
using namespace  std;

int a[110],f[10010],vis[110];
int n,m,ans=0;


void dfs(int u,int sum){
    if(sum==m){
        ans++;
        return;
    }
    if(sum>m){
        return;
    }
    vis[u]=1;
    dfs(u+1,sum+a[u]);
    vis[u]=0;
    dfs(u+1,sum);
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){ 
        cin>>a[i];
    }
    f[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=m;j>=a[i];j--){
            f[j]=f[j]+f[j-a[i]];
        }
    }
    //dfs(1,0);
    //cout<<ans;
    cout<<f[m];
    return 0;
}
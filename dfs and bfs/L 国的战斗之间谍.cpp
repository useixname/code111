#include<bits/stdc++.h>
using namespace std;
int n,m,q;
int a[105],b[105],c[105],ans,vis[105];

void dfs(int s1,int s2,int s3,int u){
    if(s2<=m&&s3<=q){
        if(u==n+1){
            ans=max(ans,s1);
            return;
        }
    }
    else{
        return;
    }
    dfs(s1+a[u],s2+b[u],s3+c[u],u+1);
    dfs(s1,s2,s3,u+1);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    dfs(0,0,0,1);
    cout<<ans;
    return 0;
}
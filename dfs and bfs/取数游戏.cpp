#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[10][10],vis[10][10],net[8][2]={{-1,0},{0,-1},{1,0},{0,1},{1,-1},{-1,1},{1,1},{-1,-1}};
int t,n,m,ans;

void dfs(int sum,int x,int y){
    if(y==m+1){
        dfs(sum,x+1,1);
        return;
    }
    if(x==n+1){
        ans=max(ans,sum);
        return;
    }
    dfs(sum,x,y+1);
    if(!vis[x][y]){
        for(int k=0;k<8;k++){
            int tx=x+net[k][0],ty=y+net[k][1];
            vis[tx][ty]++;
        }
        dfs(sum+a[x][y],x,y+1);
        for(int k=0;k<8;k++){
            int tx=x+net[k][0],ty=y+net[k][1];
            vis[tx][ty]--;
        }
        sum-=a[x][y];
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>t;
    while(t--){
        memset(vis,0,sizeof(vis));
        ans=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        dfs(0,1,1);
        cout<<ans<<'\n';
    }
    return 0;
}
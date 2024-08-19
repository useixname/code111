#include<bits/stdc++.h>
using namespace std;
const int N=55;
int m,n,ans=0;
int a[N][N],vis[N][N];
void dfs(int x,int y,int sum,int flag){
    if(x==1&&y==1&&flag==1){
        ans=max(ans,sum);
        return;
    }
    if(x==m&&y==n){
        flag=1;
    }
    if(flag==0){
        int tx=x+1;
        int ty=y+1;
        if(tx<=m&&!vis[tx][y]){
            vis[tx][y]=1;
            dfs(tx,y,sum+a[tx][y],flag);
            vis[tx][y]=0;
        }
        if(ty<=n&&!vis[x][ty]){
            vis[x][ty]=1;
            dfs(x,ty,sum+a[x][ty],flag);
            vis[x][ty]=0;
        }
    }
    if(flag==1){
        int tx=x-1;
        int ty=y-1;
        if(tx>=1&&!vis[tx][y]){
            vis[tx][y]=1;
            dfs(tx,y,sum+a[tx][y],flag);
            vis[tx][y]=0;
        }
        if(ty>=1&&!vis[x][ty]){
            vis[x][ty]=1;
            dfs(x,ty,sum+a[x][ty],flag);
            vis[x][ty]=0;
        }
    }
}



int main(){
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    dfs(1,1,0,0);
    cout<<ans;
    return 0;
}
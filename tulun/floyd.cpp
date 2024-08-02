#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int dp[N][N],p[N][N];
int n,m,a,b;

void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dp[i][j]>dp[i][k]+dp[k][j]){
                    dp[i][j]=dp[i][k]+dp[k][j];
                    p[i][j]=k;
                }
            }
        }
    }
}

void path(int i,int j){
    if(p[i][j]==0) return;
    int k=p[i][j];
    path(i,k);
    cout<<k<<" ";
    path(k,j);
}

int main(){
    ios_base::sync_with_stdio(0);
    memset(dp,0x3f3f3f3f,sizeof(dp));
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        dp[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        dp[u][v]=w;
    }
    floyd();
    cin>>a>>b;
    cout<<a<<" ";
    path(a,b);
    cout<<b;
    return 0;
}
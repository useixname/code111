#include<cstdio>
using namespace std;
const int N=35;
int a[N],dp[N][N];
int n,m,ans=0;

void dfs(int step,int u){
    if(step==m&&u!=1){
        return;
    }
    if(step==m&&u==1){
        ans++;
        return;
    }
    dfs(step+1,a[u+1]);
    dfs(step+1,a[u-1]);
}

int dfs1(int step,int u){
    if(step==0){
        if(u==1){
            return 1;
        }
        else{
            return 0;
        }
    }
    if(u>step+1&&u<n-step+1){
        return 0;
    }
    if(dp[step][u]){
        return dp[step][u];
    }
    if(u==n){
        dp[step][u]=dfs1(step-1,1)+dfs1(step-1,u-1);
    }
    else if(u==1){
        dp[step][u]=dfs1(step-1,u+1)+dfs1(step-1,n);
    }
    else{
        dp[step][u]=dfs1(step-1,u+1)+dfs1(step-1,u-1);
    }
    return dp[step][u];
}
int main(){
    scanf("%d %d",&n,&m);
    // a[0]=n;
    // for(int i=1;i<=n;i++){
    //      //dp[i][0]=1;
    //      a[i]=i;
    // }
    // a[n+1]=1;
    //dfs(0,1);
    //cout<<ans<<'\n';
    printf("%d",dfs1(m,1));
    return 0;
}
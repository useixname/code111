#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int vis[N];
int m,ans=0;

int p[N], vis1[N], cnt;
//g[i]表示i的最小质因子的1+p^1+...+p^k
int g[N], f[N];//f[i]表示i的约数和

void get_f(int n){ //筛法求约数和
  g[1] = f[1] = 1;
  for(int i=2; i<=n; i++){
    if(!vis1[i]){
      p[++cnt] = i;
      g[i] = f[i] = i+1;
    }
    for(int j=1; i*p[j]<=n; j++){
      int m = i*p[j]; 
      vis1[m] = 1;
      if(i%p[j] == 0){
        g[m] = g[i]*p[j]+1;
        f[m] = f[i]/g[i]*g[m];
        break;
      } 
      else{
        g[m] = p[j]+1;
        f[m] = f[i]*g[m];
      }
    }
  }
}

void dfs(int sum1,int sum2){
    if(sum2<=m){
        ans=max(ans,sum1);
    }
    if(sum2>m){
        return;
    }
    for(int i=1;i<=m;i++){
        if(!vis[i]){
            vis[i]=1;
            dfs(sum1+f[i],sum2+i);
            vis[i]=0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>m;
    get_f(m);
    for(int i=1;i<=m;i++){
        f[i]-=i;
    }
    dfs(0,0);
    cout<<ans;
    return 0;
}
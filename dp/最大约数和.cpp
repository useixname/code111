#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int dp[N];
int m;

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

int main(){
    ios_base::sync_with_stdio(0);
    cin>>m;
    get_f(m);
    for(int i=1;i<=m;i++){
        for(int j=m;j>=i;j--){
            dp[j]=max(dp[j-i]+f[i]-i,dp[j]);
        }
    }
    cout<<dp[m];
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

// 记忆化搜索!!! 
// 解决重叠子问题
// int dfs(int u){
// 	if(ret[u]){
// 		return ret[u];
// 	}
// 	int ans=ret[u];
// 	for(int i=0;i<u;i++){
// 		if(a[i]<a[u]){
// 			ans=max(ans,dfs(i)+a[i]);
// 		}
// 	}
// 	ret[x]=ans;
// 	return ret[x];
// }
int main(){
  int n,ans=0;
  cin>>n;
  int a[n];
  int dp[n];
  memset(dp,0,sizeof(dp));
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  for(int i=0;i<n;i++){
  	dp[i]=a[i];
    for(int j=0;j<i;j++){
      if(a[j]<a[i]){
        dp[i]=max(dp[i],dp[j]+a[i]);
      }
    }
    ans=max(ans,dp[i]);
  }
  cout<<ans;
}

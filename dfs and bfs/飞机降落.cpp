#include <bits/stdc++.h>
using namespace std;
const int N=15;
int t,n;
int a[N],b[N],c[N];
int vis[N];
bool dfs(int u,int last,int num){//last为第u号飞机的前一架飞机的最早降落时间。
  if(b[u]<last){
    return false;
  }
  if(num==n){
    return true;
  }
  for(int i=0;i<n;i++){
    if(!vis[i]){
      vis[i]=1;
      if(dfs(i,max(a[u],last)+c[u],num+1)){
        return true;
      }
      vis[i]=0;
    }
  }
  return false;
}
int main()
{
  cin>>t;
  while(t--){
    memset(vis,0,sizeof(vis));
    cin>>n;
    for(int i=0;i<n;i++){
      cin>>a[i]>>b[i]>>c[i];
      b[i]+=a[i];
    }
    bool flag=false;
    for(int i=0;i<n;i++){
        vis[i]=1;
        if(dfs(i,0,1)){
          flag=true;
          break;
        }
        vis[i]=0;
    }
    if(flag){
      cout<<"YES"<<endl;
    }
    else{
      cout<<"NO"<<endl;
    }
  }
  return 0;
}
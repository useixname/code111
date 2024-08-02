#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#define inf 1e9
using namespace std;

const int N=5010;
int n,m,a,b,c,ans,cnt;
struct edge{int v,w;};
vector<edge> e[N];
int d[N], vis[N];
priority_queue<pair<int,int>> q;
        
bool prim(int s){
  for(int i=0;i<=n;i++) d[i]=inf;
  d[s]=0; q.push({0,s});
  while(q.size()){
    int u=q.top().second; q.pop();
    if(vis[u])continue;//再出队跳过
    vis[u]=1;//标记u已出队
    ans+=d[u]; cnt++;
    for(auto ed : e[u]){
      int v=ed.v, w=ed.w;
      if(d[v]>w){
        d[v]=w;
        q.push({-d[v],v});//大根堆
      }
    }
  }
  return cnt==n;
}
int main(){
  cin>>n>>m;
  for(int i=0; i<m; i++){
    cin>>a>>b>>c;
    e[a].push_back({b,c});
    e[b].push_back({a,c});
  }
  if(!prim(1))puts("orz");
  else printf("%d\n",ans); 
  return 0;
}
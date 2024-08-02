#include<bits/stdc++.h>
using namespace std;
#define inf 2147483647
const int N=10010;
struct node{
    int v,w;
};
vector<node>e[N];
int n,m,s,ans=0,d[N],vis[N];
void dijkstra(int s){
    for(int i=0;i<=n;i++){
        d[i]=inf;
    }
    d[s]=0;
    for(int i=1;i<=n;i++){
        int u=0;
        for(int j=1;j<=n;j++){
            if(!vis[j]&&d[j]<d[u]){
                u=j;
            }
        }
        vis[u]=1;
        for(auto et:e[u]){
            int v=et.v,w=et.w;
            if(d[v]>w+d[u]){
                d[v]=w+d[u];
            }
        }
    }
}

int main(){
  cin>>n>>m>>s;
  for(int i=0; i<m; i++){
    int a,b,c;
    cin>>a>>b>>c;
    e[a].push_back({b,c});
  }
  dijkstra(s);
  for(int i=1;i<=n;i++)
    printf("%d ",d[i]);  
  return 0;
}
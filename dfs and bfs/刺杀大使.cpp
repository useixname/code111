#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int inf = 0x3f3f3f3f;
int net[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int g[1010][1010],dist[1010][1010],vis[1010][1010];
int n,m,ans=inf;
queue<PII>q;
void bfs(){
    memset(dist,0,sizeof(dist));
    while(q.size()){
        auto t=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int tx=t.first+net[i][0],ty=t.second+net[i][1];
            if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&!dist[tx][ty]){
                dist[tx][ty]=max(dist[t.first][t.second],g[tx][ty]);
                int x=dist[tx][ty];
                if(tx==n){
                    ans=min(ans,dist[tx][ty]);
                }
                else{
                    q.push({tx,ty});
                }
            }
        }
    }
}

int  main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        q.push({1,i});
        vis[1][i]=1;
        for(int j=1;j<=m;j++){
            cin>>g[i][j];
        }
    }
    bfs();
    cout<<ans;
    return 0;
}
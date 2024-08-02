#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int>PII;
const int N=10010;
int r1,c1,r2,c2;
int m[N][N];
int dist[N][N];
int net[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
queue<PII>q;

int dfs(){
  memset(dist,-1,sizeof(dist));
  q.push({r1,c1});
  dist[r1][c1]=0;
  while(q.size()){
    auto t=q.front();
    q.pop();
    for(int i=0;i<4;i++){
      int tx=t.first+net[i][0],ty=t.second+net[i][1];
      if(tx>=0&&tx<N&&ty>=0&&ty<N&&dist[tx][ty]==-1){
        dist[tx][ty]=dist[t.first][t.second]+1;
        if(tx==r2&&ty==c2){
          return dist[tx][ty];
        }
        q.push({tx,ty});
      }
    }
  }
  return -1;
}
int main()
{
  int w,m,n;
  cin>>w>>m>>n;
  r1=(m-1)/w,r2=(n-1)/w;
  if(r1%2==0){
    c1=m-r1*w-1;
  }
  else{
    c1=(r1+1)*w-m;
  }
  if(r2%2==0){
    c2=n-r2*w-1;
  }
  else{
    c2=(r2+1)*w-n;
  }
  //cout<<r1<<" "<<c1<<endl;
  //cout<<r2<<" "<<c2<<endl;
  //cout<<dfs();
  cout<<abs(r1-r2)+abs(c1-c2);
  return 0;
}
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define lc u<<1
#define rc u<<1|1
#define N 500005
int w[N];
struct Tree{
  int l,r,sum;
}tr[N*4];

void pushup(int u){ //上传
  tr[u].sum=tr[lc].sum+tr[rc].sum;
}
void build(int u,int l,int r){ 
  tr[u]={l,r,w[l]};
  if(l==r) return;
  int m=l+r>>1;
  build(lc,l,m);
  build(rc,m+1,r);
  pushup(u);
}
void change(int u,int x,int k){ //点修
  if(tr[u].l==x&&tr[u].r==x){
    tr[u].sum+=k;
    return;
  }
  int m=tr[u].l+tr[u].r>>1;
  if(x<=m) change(lc,x,k);
  if(x>m) change(rc,x,k);
  pushup(u);
}
int query(int u,int l,int r){ //区查
  if(l>tr[u].r || r<tr[u].l) return 0;
  if(l<=tr[u].l&&tr[u].r<=r) return tr[u].sum;
  return query(lc,l,r)+query(rc,l,r);
}
int main(){
  ios::sync_with_stdio(0);
  int n,m,op,x,y;  
  cin>>n>>m;
  for(int i=1;i<=n;i++) cin>>w[i];
  build(1,1,n);
  while(m--){
    cin>>op>>x>>y;
    if(op==1) change(1,x,y);
    else cout<<query(1,x,y)<<endl;
  }
  return 0;
}
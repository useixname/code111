#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define N 500005
#define LL long long
#define lc u<<1
#define rc u<<1|1
LL w[N];
struct Tree{ //线段树
  LL l,r,sum,add;
}tr[N*4];

void pushup(LL u){ //上传
  tr[u].sum=tr[lc].sum+tr[rc].sum;
}
void pushdown(LL u){ //下传
  if(tr[u].add){
    tr[lc].sum+=tr[u].add*(tr[lc].r-tr[lc].l+1),
    tr[rc].sum+=tr[u].add*(tr[rc].r-tr[rc].l+1),
    tr[lc].add+=tr[u].add,
    tr[rc].add+=tr[u].add,
    tr[u].add=0;      
  }
}
void build(LL u,LL l,LL r){ //建树
  tr[u]={l,r,w[l],0};
  if(l==r) return;
  LL m=l+r>>1;
  build(lc,l,m);
  build(rc,m+1,r);
  pushup(u);
}
void change(LL u,LL x,LL y,LL k){ //区修
  if(x>tr[u].r || y<tr[u].l) return;
  if(x<=tr[u].l && tr[u].r<=y){
    tr[u].sum+=(tr[u].r-tr[u].l+1)*k;
    tr[u].add+=k;
    return;
  }
  pushdown(u);
  change(lc,x,y,k); 
  change(rc,x,y,k);
  pushup(u);
}
LL query(LL u,LL x){ //点查
  if(x>tr[u].r || x<tr[u].l) return 0;
  if(x==tr[u].l && tr[u].r==x) return tr[u].sum;
  pushdown(u);
  return query(lc,x)+query(rc,x);
}
int main(){
  ios::sync_with_stdio(0);
  int n,m,op,x,y,k;  
  cin>>n>>m;
  for(int i=1; i<=n; i ++) cin>>w[i];
  
  build(1,1,n);
  while(m--){
    cin>>op>>x;
    if(op==2)cout<<query(1,x)<<endl;
    else cin>>y>>k,change(1,x,y,k);
  }
  return 0;
}
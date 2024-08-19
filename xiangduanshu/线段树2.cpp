#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define lc u<<1
#define rc u<<1|1
#define N 100005
#define LL long long
LL n,q,p,w[N];
struct Tree{ //线段树
  LL l,r,sum,mul,add;
}tr[N*4];

void pushup(LL u){ //上传
  tr[u].sum=(tr[lc].sum+tr[rc].sum)%p;
}
void calc(Tree &t,LL m,LL a){
  t.sum=(t.sum*m+(t.r-t.l+1)*a)%p;
  t.mul=t.mul*m%p;
  t.add=(t.add*m+a)%p;
}
void pushdown(LL u){ //下传
  calc(tr[lc],tr[u].mul,tr[u].add);
  calc(tr[rc],tr[u].mul,tr[u].add);
  tr[u].add=0;
  tr[u].mul=1; //清空懒标记
}
void build(LL u,LL l,LL r){ //建树
  tr[u]={l,r,w[r],1,0};
  if(l==r) return;
  LL mid=l+r>>1;
  build(lc,l,mid);
  build(rc,mid+1,r);
  pushup(u);
}
void change(LL u,LL l,LL r,LL m,LL a){ //区修
  if(l>tr[u].r || r<tr[u].l) return;
  if(l<=tr[u].l && tr[u].r<=r){ 
    calc(tr[u],m,a); return;
  }
  pushdown(u);
  change(lc,l,r,m,a);
  change(rc,l,r,m,a);
  pushup(u);
}
LL query(LL u,LL l,LL r){ //区查
  if(l>tr[u].r || r<tr[u].l) return 0;
  if(l<=tr[u].l&&tr[u].r<=r) return tr[u].sum;
  pushdown(u);
  return (query(lc,l,r)+query(rc,l,r))%p;
}
int main(){
  scanf("%d%d%d",&n,&q,&p);
  for(LL i=1; i<=n; i++) scanf("%d",&w[i]);
  build(1,1,n);
  while(q--){
    LL op,x,y,k;
    scanf("%lld%lld%lld",&op,&x,&y);
    if(op==1)
      scanf("%lld",&k), change(1,x,y,k,0);
    else if(op==2)
      scanf("%lld",&k), change(1,x,y,1,k);
    else printf("%lld\n",query(1,x,y));
  }
  return 0;
}
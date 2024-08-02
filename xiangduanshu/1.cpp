#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define N 500005
#define ll long long
#define lc u<<1
#define rc u<<1|1
ll w[N];

struct node{
    ll l,r,sum,add;
}tree[N*4];

void build(ll u,ll l,ll r){
    tree[u]={l,r,w[l],0};
    if(l==r) return;
    ll m=l+r>>1;
    build(lc,l,m);
    build(rc,m+1,r);
    tree[u].sum=tree[lc].sum+tree[rc].sum;
}

void pushup(ll u){
    tree[u].sum=tree[lc].sum+tree[rc].sum;
}

void pushdown(ll u){
    if(tree[u].add){
        tree[lc].sum+=tree[u].add*(tree[lc].r-tree[lc].l+1);
        tree[rc].sum+=tree[u].add*(tree[rc].r-tree[rc].l+1);
        tree[lc].add+=tree[u].add;
        tree[rc].add+=tree[u].add;
        tree[u].add=0;
    }
}

void change1(ll u,ll x,ll k){
    if(x>tree[u].r||x<tree[u].l) return;
    if(x==tree[u].l&&x==tree[u].r){
        tree[u].sum+=k*(tree[u].r-tree[u].l+1);
        tree[u].add+=k;
        return;
    }
    ll m=tree[u].l+tree[u].r>>1;
    pushdown(u);
    change1(lc,x,k);
    change1(rc,x,k);
    pushup(u);
}

void change(ll u,ll x,ll y,ll k){
    if(x>tree[u].r||y<tree[u].l) return;
    if(x<=tree[u].l&&y>=tree[u].r){
        tree[u].sum+=k*(tree[u].r-tree[u].l+1);
        tree[u].add+=k;
        return;
    }
    ll m=tree[u].l+tree[u].r>>1;
    pushdown(u);
    change(lc,x,y,k);
    change(rc,x,y,k);
    pushup(u);
}

ll query(ll u,ll x){
    if(x>tree[u].r||x<tree[u].l) return 0;
    if(x==tree[u].l&&x==tree[u].r) return tree[u].sum;
    pushdown(u);
    ll m=tree[u].l+tree[u].r>>1;
    if(x<=m) return query(lc,x);
    else return query(rc,x);
}

ll query1(ll u,ll x,ll y){
    if(x>tree[u].r||y<tree[u].l) return 0;
    if(x<=tree[u].l&&y>=tree[u].r) return tree[u].sum;
    pushdown(u);
    ll m=tree[u].l+tree[u].r>>1;
    ll sum=0;
    if(x<=m) sum+=query1(lc,x,y);
    else sum+=query1(rc,x,y);
    return sum;
}

int main(){
  ios::sync_with_stdio(0);
  int n,m,op,x,y,k,d;  
  cin>>n>>m;
  for(int i=1; i<=n; i ++) cin>>w[i];
  
  build(1,1,n);
  while(m--){
    cin>>op>>x;
    if(op==2)cout<<query(1,x)<<endl;
    else cin>>y>>k>>d;change(1,x,y,k);
  }
  return 0;
}
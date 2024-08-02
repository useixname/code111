#include<bits/stdc++.h>
using namespace std;
#define lc p<<1
#define rc p<<1|1
const int N=1e4+10;
int n,w[N];

struct tree{
    int l,r,sum,add;
}tree[4*N];

void build(int p,int l,int r){
    tree[p]={l,r,w[l],0};
    if(l==r){
        return;
    }
    int m=l+r>>1;
    build(lc,l,m);
    build(rc,m+1,r);
    tree[p].sum=tree[lc].sum*tree[rc].sum;
}

void pushup(int p){
    tree[p].sum=tree[lc].sum*tree[rc].sum;
}

void pushdown(int p){
    if(tree[p].add){
        tree[lc].sum+=tree[p].add*(tree[lc].r-tree[lc].l+1);
        tree[rc].sum+=tree[p].add*(tree[rc].r-tree[rc].l+1);
        tree[lc].add+=tree[p].add;
        tree[rc].add+=tree[p].add;
        tree[p].add=0;
    }
}

void updata(int p,int x,int y,int k){
     if(x<=tree[p].l&&y>=tree[p].r){
        tree[p].sum+=k*(tree[p].r-tree[p].l+1);
        tree[p].add+=k;
        return;
     }
     int m=tree[p].l+tree[p].r>>1;
     pushdown(p);
     if(m>=x){
        updata(lc,x,y,k);
     }
     else{
        updata(rc,x,y,k);
     }
     pushup(p);
}

int query(int p,int x,int y){
    if(x<=tree[p].l&&y>=tree[p].r){
        return tree[p].sum;
    }
    int m=tree[p].l+tree[p].r>>1;
    int sum=1;
    if(x<=m){
        sum*=query(lc,x,y);
    }
    else{
        sum*=query(rc,x,y);
    }
    return sum;
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    build(1,1,n);
    cout<<query(1,1,3);
    return 0;
}
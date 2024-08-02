#include<bits/stdc++.h>
using namespace std;

#define lc p<<1
#define rc p<<1|1
#define INF 0x7fffffff
const int N=1e5+10;
int w[N];
struct node{
    int l,r,Min=INF;
}tr[N*4];

void build(int p,int l,int r){
    tr[p]={l,r,w[l]};
    if(l==r){
        //tr[p].Min=w[l];
        return;
    }
    int m=l+r>>1;
    build(lc,l,m);
    build(rc,m+1,r);
    tr[p].Min=min(tr[lc].Min,tr[rc].Min);
}

int query(int p,int x,int y){
    if(tr[p].l>=x&&tr[p].r<=y){
        return tr[p].Min;
    }
    int m=tr[p].l+tr[p].r>>1;
    int ans=INF;
    if(x<=m) ans=min(query(lc,x,y),ans);
    if(y>m) ans=min(query(rc,x,y),ans);
    return ans;
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    build(1,1,n);
    while(m--){
        int x,y;
        cin>>x>>y;
        cout<<query(1,x,y)<<" ";
    }
}
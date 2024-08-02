#include<bits/stdc++.h>
using namespace std;

#define lc p<<1
#define rc p<<1|1
const int N=51e5+10;
int a[N];

struct node{
    int l,r,sum;
}tr[N*4];

void build(int p,int l,int r){
    tr[p]={l,r,a[l]};
    if(l==r){
        return;
    }
    int m=l+r>>1;
    build(lc,l,m);
    build(rc,m+1,r);
    tr[p].sum=tr[lc].sum+tr[rc].sum;  
}

void updata(int p,int x,int k){//单点修改
    if(tr[p].l==x&&tr[p].r==x){
        tr[p].sum+=k;
        return;
    }
    int m=tr[p].l+tr[p].r>>1;
    if(x<=m) updata(lc,x,k);
    else updata(rc,x,k);
    tr[p].sum=tr[lc].sum+tr[rc].sum;
}


int query(int p,int x,int y){//区间查询
    if(tr[p].l>=x&&tr[p].r<=y){
        return tr[p].sum;
    }
    int m=tr[p].l+tr[p].r>>1;
    int sum=0;
    if(x<=m) sum+=query(lc,x,y);
    if(y>m) sum+=query(rc,x,y);
    return sum;
}

int main(){
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    build(1,1,n);
    while(k--){
        int q,x,y;
        cin>>q>>x>>y;
        if(q==1){
            updata(1,x,y);
        }
        else{
            cout<<query(1,x,y)<<'\n';
        }
    }
    return 0;
}
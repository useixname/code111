#include<iostream>
using namespace std;
#define ll long long
ll w[100005];
struct point{
    ll sum;
    ll tag;
} a[400005];
inline int ls(int root){return root<<1;}
inline int rs(int root){return root<<1|1;}
inline void up(int root){a[root].sum=a[ls(root)].sum+a[rs(root)].sum;}
void build(int root,int l,int r){
    a[root].tag=0;int mid=(l+r)>>1;
    if(l==r){a[root].sum=w[l];return;}
    build(ls(root),l,mid);build(rs(root),mid+1,r);
    up(root);
}
inline void pd(int root,int l,int r){
    int mid=(l+r)>>1;
    a[ls(root)].tag+=a[root].tag;
    a[rs(root)].tag+=a[root].tag;
    a[ls(root)].sum+=a[root].tag*(mid-l+1);
    a[rs(root)].sum+=a[root].tag*(r-mid);
    a[root].tag=0;
}
void add(int root,int l,int r,int ql,int qr,ll x){
    if(ql<=l&&qr>=r){a[root].tag+=x;a[root].sum+=(r-l+1)*x;return;}
    int mid=(l+r)>>1;
    pd(root,l,r);
    if(ql<=mid)add(ls(root),l,mid,ql,qr,x);
    if(qr>mid) add(rs(root),mid+1,r,ql,qr,x);
    up(root);
    return;
}
ll query(int root,int l,int r,int ql,int qr){
    if(ql<=l&&qr>=r)
        return a[root].sum;
    int mid=(l+r)>>1,ret=0;
    pd(root,l,r);
    if(ql<=mid)ret+=query(ls(root),l,mid,ql,qr);
    if(qr>mid)ret+=query(rs(root),mid+1,r,ql,qr);
    return ret;
}
int main()
{
    int n,m,opt,l,r,k,d,t;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>w[i];
    for(int i=n-1;i>0;i--)
        w[i+1]=w[i+1]-w[i];
    build(1,1,n);
    for(int i=0;i<m;i++){
        cin>>opt;
        if(opt==1){
            cin>>l>>r>>k>>d;
            add(1,1,n,l,l,k);
            if(l+1<=r)add(1,1,n,l+1,r,d);
            if(r<n)add(1,1,n,r+1,r+1,-(k+d*(r-l)));
        }
        else{
            cin>>t;
            cout<<query(1,1,n,1,t)<<endl;
        }
        
    }
    return 0;
}
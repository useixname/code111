#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+10;
ll a[N],ans=0;
int m,n;

int lower(int l,int r,int x){
    while(l+1<r){
        int mid=(l+r)>>1;
        if(a[mid]<=x){
            l=mid;
        }
        else{
            r=mid;
        }
    }
    l=l==0?l+1:l;
    int ret=abs(a[l]-x);
    return ret;
}
int upper(int l,int r,int x){
    while(l+1<r){
        int mid=(l+r)>>1;
        if(a[mid]>=x){
            r=mid;
        }
        else{
            l=mid;
        }
    }
    int ret=abs(a[r]-x);
    return ret;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=m;i++){
        int x;
        cin>>x;
        int a=lower(0,n+1,x),b=upper(0,n+1,x);
        ans+=a<=b?a:b;
    }
    cout<<ans;
    return 0;
}
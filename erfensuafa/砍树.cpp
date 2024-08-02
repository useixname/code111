#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
ll n,m;
ll a[N];

bool chk(int mid){
    ll tot=0;
    ll pos=upper_bound(a+1,a+n+1,mid) - a;
    if(a[pos]<=mid){
        return tot>=m;
    }
    for(ll i=pos;i<=n;i++){
        tot+=a[i]-mid;
    }
    return tot>=m;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    ll l=0,r=a[n]+1;
    while(l+1<r){
        ll mid=l+r>>1;
        if(chk(mid)){
            l=mid;
        }
        else{
            r=mid;
        }
    }
    cout<<l;
    return 0;
}
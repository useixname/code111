#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int a[N],ans1,ans2;
int n,k;

bool chk(int x){
    int cnt=0,s=0;
    for(int i=1;i<=n;i++){
        s+=a[i];
        if(s<0){
            s=0;
        }
        if(s>=x){
            cnt++;
            s=0;
        }
    }
    return cnt<=k;
}
bool chk1(int x){
    int cnt=0,s=0;
    for(int i=1;i<=n;i++){
        s+=a[i];
        if(s<0){
            s=0;
        }
        if(s>=x){
            cnt++;
            s=0;
        }
    }
    return cnt>=k;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int l=0,r=1e18+1;
    while(l+1<r){
        int mid=l+r>>1;
        if(chk(mid)) r=mid;
        else l=mid;
    }
    ans1=r; 
    int cnt=0,s=0;
    for(int i=1;i<=n;i++){
        s+=a[i];
        if(s<0){
            s=0;
        }
        if(s>=ans1){
            cnt++;
            s=0;
        }
    }
    if(cnt!=k){
        cout<<-1;
        return 0;
    }
    l=0,r=1e18+1;
    while(l+1<r){
        int mid=l+r>>1;
        if(chk1(mid)) l=mid;
        else r=mid;
    }
    ans2=l;
    cnt=0,s=0;
    for(int i=1;i<=n;i++){
        s+=a[i];
        if(s<0){
            s=0;
        }
        if(s>=ans2){
            cnt++;
            s=0;
        }
    }
    if(cnt!=k){
        cout<<-1;
        return 0;
    }
    cout<<ans1<<" "<<ans2;
    return 0;
}
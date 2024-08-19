#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f
const int N=2e5+10;
int n,a[N];
int ansl[N],ansr[N],ans=-inf;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    ansl[0]=ansr[n+1]=-inf;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ansl[i]=max(ansl[i-1]+a[i],a[i]);
    }
    for(int i=n;i>=1;i--){
        ansr[i]=max(ansr[i+1]+a[i],a[i]);
    }
    for(int i=2;i<=n-1;i++){
        ans=max(ansl[i-1]+ansr[i+1],ans);
    }
    cout<<ans;
    return 0;
}
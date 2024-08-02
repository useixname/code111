#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
map<ll,ll> m; 
ll a[N];
int n,k,ans=0;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        m[a[i]]++;
        a[i]+=k;
    }
    for(int i=1;i<=n;i++){
        ans+=m[a[i]];
    }
    cout<<ans;
    return 0;
}
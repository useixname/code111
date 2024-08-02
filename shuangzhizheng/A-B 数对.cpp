#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll a[N];
ll n,c,ans=0;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>c;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int i=1,j=1;
    for(int k=1;k<=n;k++){
        while(i<=n && a[i]<a[k]+c) i++;
        while(j<=n && a[j]<=a[k]+c) j++;
        ans+=(j-i);
    }
    cout<<ans;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n,dp[5005],ans=1;

struct node{
    int l,w;
    bool operator<(const node & pa) const{
        if(l==pa.l){
            return w<pa.w;
        }
        return l<pa.l;
    }
}a[5010];

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].l>>a[i].w;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        dp[i]=1;
        for(int j=1;j<i;j++){
            if(a[i].w<a[j].w){
                dp[i]=max(dp[j]+1,dp[i]);
            }
        }
        ans=max(ans,dp[i]);
    }
    cout<<ans;
    return 0;
}
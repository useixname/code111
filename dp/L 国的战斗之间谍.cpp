#include<bits/stdc++.h>
using namespace std;
int n,m,q;
int a[105],b[105],c[105],dp[1005][1005];

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=m;j>=b[i];j--){
            for(int k=q;k>=c[i];k--){
                dp[j][k]=max(dp[j-b[i]][k-c[i]]+a[i],dp[j][k]);
            }
        }
    }
    cout<<dp[m][q];
    return 0;
}
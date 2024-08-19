#include<bits/stdc++.h>
using namespace std;

int n,m;
int dp[105][1010],w[105],v[105];

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>w[i]>>v[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=m;j>=w[i];j--){
            dp[i][j]=max(dp[i-1][j-w[i]]+v[i],dp[i-1][j]);
        }
    }
    cout<<dp[n][m];
    return 0;
}
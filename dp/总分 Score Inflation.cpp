#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int dp[N];
int n,m;
int w[N],v[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin>>m>>n;
    for(int i=1;i<=n;i++){
        cin>>w[i]>>v[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=v[i];j<=m;j++){
            dp[j]=max(dp[j-v[i]]+w[i],dp[j]);
        }
    }
    cout<<dp[m];
    return 0;
}
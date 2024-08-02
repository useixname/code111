#include<bits/stdc++.h>
using namespace std;

const int N=1005;

int n,m;
int dp[N][N];
int v[N],w[N];

int main(){
	cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>v[i]>>w[i];
    }
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        dp[i][0]=0;
        for(int j=0;j<=m;j++){
            if(j>=v[i]){
                dp[i][j]=max(dp[i][j-v[i]]+w[i],dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[n][m]<<'\n';
    return 0;
}
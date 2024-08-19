#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n=s.size();
    int dp[n+1][n+1];
    memset(dp,0,sizeof(dp));
    for(int i=n;i>=1;i--){
        dp[i][i]=1;
        for(int j=i+1;j<=n;j++){
            if(s[i-1]==s[j-1]){
                dp[i][j]=dp[i+1][j-1]+2;
            }
            else{
                dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
            }
        }
    }
    cout<<dp[1][n];
}
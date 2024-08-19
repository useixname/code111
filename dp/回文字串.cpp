#include<bits/stdc++.h>
using namespace std;
int dp[1010][1010];
string s;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>s;
    int n=s.size();
    for(int i=n-1;i>=0;i--){
        dp[i][i]=1;
        for(int j=i+1;j<n;j++){
            if(s[i]==s[j]){
                dp[i][j]=max(dp[i+1][j-1]+2,dp[i][j]);
            }
            else{
                dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
            }
        }
    }
    cout<<n-dp[0][n-1];
    return 0;
}
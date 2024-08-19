#include<bits/stdc++.h>
using namespace std;

int dp[105][105];
char s[105];

int main(){
    while(scanf("%s",s+1)!=EOF){
        memset(dp,0,sizeof(dp));
        int n=strlen(s+1);
        if(s[1]=='e'){
            break;
        }
        for(int len=1;len<=n;len++){
            for(int j=1;j+len<=n+1;j++){
                int end=j+len-1;
                if(s[j]==s[end]){
                    dp[j][end]=dp[j+1][end-1]+2;
                }
                for(int i=j;i<end;i++){
                    dp[j][end]=max(dp[j][end],dp[j][i]+dp[i+1][end]);
                }
            }
        }
        cout<<dp[1][n]<<'\n';
    }
    return 0;
}
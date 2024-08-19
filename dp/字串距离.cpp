#include<bits/stdc++.h>
using namespace std;
const int N=2010;
string s1,s2;
int dp[N][N],k;

int main(){
    cin>>s1>>s2>>k;
    int m=s1.length(),n=s2.length();
    for(int i=1;i<=m;i++){
        dp[i][0]=i*k;
    }
    for(int i=1;i<=n;i++){
        dp[0][i]=i*k;
    }
    dp[0][0]=0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=min((min(dp[i-1][j-1]+abs(s1[i-1]-s2[j-1]),dp[i-1][j]+k)),dp[i][j-1]+k);
        }
    }
    cout<<dp[m][n];
    return 0;
}
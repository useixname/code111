#include<bits/stdc++.h>
using namespace std;
const int N=55;
int dp[N<<1][N][N];
int m,n;
int a[N][N];

int main(){
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    dp[0][1][1]=a[1][1];
    for(int k=1;k<=m+n-2;k++){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                int y1=k+2-i,y2=k+2-j;
                if(y1<1||y2<1){
                    continue;
                }
                dp[k][i][j]=max(max(dp[k-1][i][j],dp[k-1][i-1][j-1]),max(dp[k-1][i-1][j],dp[k-1][i][j-1]))+a[i][y1]+a[j][y2];
                if(i==j&&y1==y2){
                    dp[k][i][j]-=a[i][y1];
                }
            }
        }
    }
    cout<<dp[n+m-2][m][m];
    return 0;
}
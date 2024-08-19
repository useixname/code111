#include<bits/stdc++.h>
using namespace std;

int dp[105][105],a[105],b[105];
int n,m;
int d[6][6]=
{
	{0,0,0,0,0,0},
	{0,5,-1,-2,-1,-3},
	{0,-1,5,-3,-2,-4},
	{0,-2,-3,5,-2,-2},
	{0,-1,-2,-2,5,-1},
	{0,-3,-4,-2,-1,0}
};

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        char ch;
        cin>>ch;
        switch(ch){
            case 'A':
                a[i]=1;break;
            case 'C':
                a[i]=2;break;
            case 'G':
                a[i]=3;break;
            case 'T':
                a[i]=4;break;
        }
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        char ch;
        cin>>ch;
        switch(ch){
            case 'A':
                b[i]=1;break;
            case 'C':
                b[i]=2;break;
            case 'G':
                b[i]=3;break;
            case 'T':
                b[i]=4;break;
        }
    }
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        dp[i][0]=dp[i-1][0]+d[a[i]][5];
    }
    for(int j=1;j<=m;j++){
        dp[0][j]=dp[0][j-1]+d[b[j]][5];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=max(max(dp[i-1][j-1]+d[a[i]][b[j]],dp[i-1][j]+d[a[i]][5]),dp[i][j-1]+d[b[j]][5]);
        }
    }
    cout<<dp[n][m];
    return 0;
}
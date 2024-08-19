#include <iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
#define INF 0x3f3f3f
int stone[105];
int dp[105][105];
int sum[105];
int main()
{
    int n;
    scanf("%d",&n);
    memset(sum,0,sizeof(sum));
    memset(dp,INF,sizeof(dp));
    for(int  i =1;i<=n;i++){
        scanf("%d",&stone[i]);
        sum[i] = sum[i - 1] + stone[i];//重量
        dp[i][i] = 0;
    }
    for(int len = 1;len<=n;len++){//枚举长度
        for(int j = 1;j+len<=n+1;j++){//枚举起点，ends<=n
            int ends = j+len - 1;
            for(int i = j;i<ends;i++){//枚举分割点
                dp[j][ends] = min(dp[j][ends],dp[j][i]+dp[i+1][ends]+sum[ends]-sum[j-1]);//更新状态
            }
        }
    }
    cout<<dp[1][n]<<endl;
    return 0;
}
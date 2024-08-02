#include <iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
#define INF 0x3f3f3f
int stone[105];
int dpmin[205][205];//最小
int dpmax[205][205];//最大
int sum[205];
int main()
{
    int n;
    scanf("%d",&n);
    memset(sum,0,sizeof(sum));
    memset(dpmin,INF,sizeof(dpmin));
    memset(dpmax,-1,sizeof(dpmax));
    for(int  i =1;i<=n;i++){
        scanf("%d",&stone[i]);
        sum[i] = sum[i - 1] + stone[i];
        dpmin[i][i] = 0;
        dpmax[i][i] = 0;
    }
    for(int i = 1;i<=n-1;i++){
        sum[i+n] = sum[i+n-1]+stone[i];//展开的n后面的n-1~1重量
        dpmin[i+n][i+n] = 0;
        dpmax[i+n][i+n] = 0;
    }
    for(int len = 1;len<=n;len++){//长度还是最大n
        for(int j = 1;j+len<=2*n;j++){//起点枚举最大到2*n-1,ends<=2*n-1
            int ends = j+len - 1;
            for(int i = j;i<ends;i++){//注意！i<ends！！！因为i=ends时，dp[ends+1][ends]是不成立的！
                dpmin[j][ends] = min(dpmin[j][ends],dpmin[j][i]+dpmin[i+1][ends]+sum[ends]-sum[j-1]);
                dpmax[j][ends] = max(dpmax[j][ends],dpmax[j][i]+dpmax[i+1][ends]+sum[ends]-sum[j-1]);
            }
        }
    }
    int ansmin = 0xfffffff;
    int ansmax = -1;
    for(int i = 1;i<=n;i++){
        ansmin = min(ansmin,dpmin[i][i+n-1]);//找1~n,2~n~1,3~n~2....的合并n个堆的中最大和最小的值
        ansmax = max(ansmax,dpmax[i][i+n-1]);
    }
    cout<<ansmin<<endl;
    cout<<ansmax<<endl;
    return 0;
}
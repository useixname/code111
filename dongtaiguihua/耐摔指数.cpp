#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stdio.h>
#include <iomanip>
#include <cstring>
#include <map>
#include <set>
#define ll long long 
#define ld long double
#define sl unsigned long long
using namespace std;
typedef pair<ld,ld> PII;
const int inf=0x3f3f3f3f;
const ll mm=0x7fffffffffffffffL;
const int mod=1000000007;
int n,dp[4][10005];//dp[i][j]表示楼高为j时i部手机的测试次数 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for(int j=1;j<=n;j++){
        dp[1][j]=j;//初始化对于一部手机所测试次数为楼层数 
    }
    for(int i=2;i<=3;i++){//测试2或3部手机时的测试次数 
        for(int j=1;j<=n;j++){//对于每一个高度为j的楼层相应的手机数记录所测次数
            dp[i][j]=j;//初始化便于下方取min 
            for(int k=1;k<j;k++){//对于该j高的楼层从1~j-1上测试手机寻找最优策略
                dp[i][j]=min(dp[i][j],max(dp[i-1][k-1],dp[i][j-k])+1);//min表示最优策略 max表示最差运气
            }
        }
    }
    cout<<dp[3][n];
/*对于最差运气 若只存在一部手机只能从第1层往上到最高层 因为最差运气无论从中间哪一层扔手机
一定会碎使耐摔指数得不到 所以只能从第1层往上测试 但又因为最差运气 所以一定是在最高层才出
结果 所以dp[1][j]=j最差运气使得你每次所测试的情况最差(既是你所测试次数最大) 对于最优策略表
示的是 所得到的最少测试次数是说在m部手机的情况下(m>1)我们可以选择每一个楼层进行测试 从中取
最小的测试结果为所得答案 那么对于某一层楼k我们会有两种情况 一种是摔坏 一种是没摔坏 若摔坏
了且只剩一部手机那么结果就是dp[m-1][k-1]=k-1(m-1=1)若摔坏了还剩不止一部 那么结果为dp[m-1][k-1]
(m-1!=1)则dp可以从上一次遍历读表得到 若没摔坏 则结果为dp[m][k-j](k-j表示还剩k-j层楼可以测试)
也是从读表得到值 由于最差运气我们每一层楼锁得到的两种不同结果(摔坏和没摔坏)肯定是取最大的因为
运气差所以不会得到较小的测试次数 然后再对每一层楼测试的结果取min每取一次就更新dp[m][j] 所以
状态转移方程为dp[m][j]=min(dp[m][j],max(dp[m-1][k-1],dp[m][j-k])+1)加1表示加上原来的楼层的
测试次数 所以在我们第一次更新dp[i][j]时要初始化一个最大值j以便于取min更新dp[i][j]*/    
    return 0;              
}
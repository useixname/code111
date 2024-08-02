#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=1e3+100;
ll a[maxn];
ll b[maxn];
ll tmp[100000];
ll dp[maxn][maxn][2];//1是这个变化，0是不变化 
ll f(ll x){
	
	ll res = 0;
    while (x > 0) {
        res = (res << 1) | (x & 1);// 将x的最后一位加到res的最后
        x >>= 1;// 将x右移一位
    }
    return res;
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=f(a[i]);
	}
	for(int i=1;i<=n;i++){
		dp[i][0][0]=dp[i-1][0][0]+a[i];
		for(int j=1;j<=m;j++){
			dp[i][j][0]=max(dp[i-1][j][0],dp[i-1][j][1])+a[i];
			dp[i][j][1]=max(dp[i-1][j-1][0],dp[i-1][j][1])+b[i];
		}
	}
	ll ans=0;
	for(int j=0;j<=m;j++){
		ans=max(ans,max(dp[n][j][0],dp[n][j][1]));
	}
	cout<<ans<<endl;
}

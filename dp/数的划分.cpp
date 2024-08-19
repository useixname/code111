#include<iostream>
using namespace std;

int dp[205][8];

int main(){
	int n,k;
	cin>>n>>k;
	//memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			if(i>=j){
				dp[i][j]=dp[i-j][j]+dp[i-1][j-1];
			}
		}
	}
	cout<<dp[n][k];
}
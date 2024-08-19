#include<bits/stdc++.h>
using namespace std;

int n;
int ans=999999;

void dfs(int tot,int k,int last)
/*
三个参数：
tot是之前所有选的数的和，
k是选了几个数（用于更新ans）
last是上次选的数（保证不降序排列，不会出现1^4+2^4和
2^4+1^4分别处理的尴尬情况）
*/
{
	if(k>ans) return; //剪枝
	if(tot>n) return; //边界条件
	
	if(tot==n) //达到n了，更新答案
	{
		if(ans>k) ans=k;
		return;
	}
	
	int i;
	
	for(i=last;i*i*i*i<=n-tot;) i++;
	
	for(;i>=last;i--) //从后往前搜
		dfs(tot+i*i*i*i,k+1,i);
}

int main()
{
	cin>>n;
	dfs(0,0,1); //爆搜大法牛B！！！
	cout<<ans;
}
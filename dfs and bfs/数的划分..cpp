#include<bits/stdc++.h>
using namespace std;
long long a[105];
long long n,k,sum;//n:拆分的数,k:拆分成几份,sum:有多少种
long long now;//已经拆分后的数字总和
void dfs(int x,int last)//拆分到第几份,上一个拆分的内容
{
	if(x>k||now>n) return;
	if(x==k&&n==now)
	{
		sum++;
		return;
	}
	for(int i=last; i<=n; i++)//为了保证不重复,用从小到大的顺序进行拆分
	{
		if(now+i<=n);
		{
			now+=i;
			dfs(x+1,i);
			now-=i;
		}
	}
}
int main()
{
	cin>>k>>n;
	for(int i=1;i<=k;i++){
		cin>>a[i];
	}
	dfs(0,1);
	cout<<sum;
    return 0;
}
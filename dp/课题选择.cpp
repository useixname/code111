#include<bits/stdc++.h>
using namespace std;
long long f[21][300],n,m,j,k,A[210],B[210];
//f[a][b]意思是前a个课题写b篇的最大值 
int main()
{
	long long int p,a,b,c,d,e;
	cin>>m>>n;
	for(a=1;a<=n;a++)cin>>A[a]>>B[a];
	for(a=1;a<=n;a++)//前a个课题
	{
		for(b=1;b<=m;b++)//选b篇写
		{
			for(c=0;c<=b;c++)//1.见下
			{
				p=A[a]*pow(c,B[a]);//当前的值
				if(f[a][b]==0||a==1)f[a][b]=f[a-1][b-c]+p;
				else//因为当f[a][b]初始赋值或a=1需要特判
				f[a][b]=min(f[a-1][b-c]+p,f[a][b]);//状态转移
			}
		}
	}
	cout<<f[n][m];
}
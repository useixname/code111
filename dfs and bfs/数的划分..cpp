#include<bits/stdc++.h>
using namespace std;
long long n,k,sum;//n:��ֵ���,k:��ֳɼ���,sum:�ж�����
long long now;//�Ѿ���ֺ�������ܺ�
void dfs(int x,int last)//��ֵ��ڼ���,��һ����ֵ�����
{
	if(x==k&&n==now)
	{
		sum++;
		return;
	}
	for(int i=last; i<=n; i++)//Ϊ�˱�֤���ظ�,�ô�С�����˳����в��
	{
		if(now+i<=n)
		{
			now+=i;
			dfs(x+1,i);
			now-=i;
		}
	}
}
int main()
{
	cin>>n>>k;
	dfs(0,1);
	cout<<sum;
    return 0;
}
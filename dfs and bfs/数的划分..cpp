#include<bits/stdc++.h>
using namespace std;
long long a[105];
long long n,k,sum;//n:��ֵ���,k:��ֳɼ���,sum:�ж�����
long long now;//�Ѿ���ֺ�������ܺ�
void dfs(int x,int last)//��ֵ��ڼ���,��һ����ֵ�����
{
	if(x>k||now>n) return;
	if(x==k&&n==now)
	{
		sum++;
		return;
	}
	for(int i=last; i<=n; i++)//Ϊ�˱�֤���ظ�,�ô�С�����˳����в��
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
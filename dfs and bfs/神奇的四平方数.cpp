#include<bits/stdc++.h>
using namespace std;

int n;
int ans=999999;

void dfs(int tot,int k,int last)
/*
����������
tot��֮ǰ����ѡ�����ĺͣ�
k��ѡ�˼����������ڸ���ans��
last���ϴ�ѡ��������֤���������У��������1^4+2^4��
2^4+1^4�ֱ�������������
*/
{
	if(k>ans) return; //��֦
	if(tot>n) return; //�߽�����
	
	if(tot==n) //�ﵽn�ˣ����´�
	{
		if(ans>k) ans=k;
		return;
	}
	
	int i;
	
	for(i=last;i*i*i*i<=n-tot;) i++;
	
	for(;i>=last;i--) //�Ӻ���ǰ��
		dfs(tot+i*i*i*i,k+1,i);
}

int main()
{
	cin>>n;
	dfs(0,0,1); //���Ѵ�ţB������
	cout<<ans;
}
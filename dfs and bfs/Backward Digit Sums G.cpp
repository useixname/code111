#include <bits/stdc++.h>//����ͷ�ļ�
using namespace std;
int n,p;//����ر�
int a[13];//����ر�
int c[13][13];//������Ǳر�
bool b[13];//���رر�
void dfs(int dep,int s)
{
	if(s>p)//��������ۼӵ����Ѿ������˸����������ͷ���
		return;
	if(dep>n)//����Ѿ�������n�������ͷ���
	{
		if(s==p)//����𰸸������������
		{
			cout<<a[1];
			for(int i=2;i<=n;i++)
				cout<<" "<<a[i];//���
			exit(0);//��ֹ����
		}
		return;//���û������𰸣��ͷ���
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]==false)//�����ǰ�����û���ù�
		{
			b[i]=true;//��ǳ��ù�
			a[dep]=i;//�����dep��ȡ����
			dfs(dep+1,s+i*c[n][dep]);
			b[i]=false;//ע������Ҫ��״̬�ع飬��ȻTLE
		}
	}
}
int main()
{
	cin>>n>>p;//����
	c[1][1]=1;
	for(int i=2;i<=n;i++)
		for(int j=1;j<=i;j++)
			c[i][j]=c[i-1][j]+c[i-1][j-1];//�����������
	dfs(1,0);//��������֮��
	return 0;
}
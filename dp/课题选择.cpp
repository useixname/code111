#include<bits/stdc++.h>
using namespace std;
long long f[21][300],n,m,j,k,A[210],B[210];
//f[a][b]��˼��ǰa������дbƪ�����ֵ 
int main()
{
	long long int p,a,b,c,d,e;
	cin>>m>>n;
	for(a=1;a<=n;a++)cin>>A[a]>>B[a];
	for(a=1;a<=n;a++)//ǰa������
	{
		for(b=1;b<=m;b++)//ѡbƪд
		{
			for(c=0;c<=b;c++)//1.����
			{
				p=A[a]*pow(c,B[a]);//��ǰ��ֵ
				if(f[a][b]==0||a==1)f[a][b]=f[a-1][b-c]+p;
				else//��Ϊ��f[a][b]��ʼ��ֵ��a=1��Ҫ����
				f[a][b]=min(f[a-1][b-c]+p,f[a][b]);//״̬ת��
			}
		}
	}
	cout<<f[n][m];
}
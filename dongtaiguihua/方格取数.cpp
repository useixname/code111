#include<bits/stdc++.h>
using namespace std;
const int maxn=10;
int a[maxn][maxn],f[maxn<<1][maxn][maxn],n;
int main()
{
	scanf("%d",&n);
	memset(a,0,sizeof(a));
	while (1)
	{
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		if (x==0 && y==0 && z==0) break;
		a[x][y]=z;
	}
	f[0][1][1]=a[1][1];//��ʼ�� 
	for (int i=1;i<=2*n-2;i++)//��Ϊ�����2n-2����x1+x2=i+2 
		for (int x1=1;x1<=n;x1++)
			for (int x2=1;x2<=n;x2++)
			{
				int y1=i+2-x1,y2=i+2-x2;//��������� 
				if (y1<1 || y2<1) continue;//�ж��Ƿ�Խ�� 
				f[i][x1][x2]=max(f[i-1][x1][x2],max(f[i-1][x1-1][x2],max(f[i-1][x1][x2-1],f[i-1][x1-1][x2-1])))+a[x1][y1]+a[x2][y2];//����˵��ת�� 
				if (x1==x2 && y1==y2) f[i][x1][x2]-=a[x1][y1];	//����ߵ�ͬһ����ͼ�һ�� 
			}
	printf("%d",f[n*2-2][n][n]);//Ŀ��״̬ 
	return 0;
}
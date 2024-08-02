#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN=500;
int n,m;
struct coffee
{
	int v,t;
	double avr;//��Ȩֵt*x-v
	bool operator<(const coffee a)const
	{
		return avr<a.avr;
	}
}a[MAXN];
double ans,l,r;


void input(void)
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	 cin>>a[i].v;
	for(int i=1;i<=n;i++)
 	 cin>>a[i].t;
}

bool check(const double x)
{
	for(int i=1;i<=n;i++)
	 a[i].avr=x*a[i].t-a[i].v;//��ÿ����Ȩֵ
    sort(a+1,a+n+1);//��С��������
	double tot=0;
	for(int i=1;i<=m;i++)//ȡǰm��С��
	 tot+=a[i].avr;
	return tot<=0;
}

void binary(void)
{
	for(int i=1;i<=n;i++)
	 if(a[i].v*1.0/a[i].t>r)
	  r=a[i].v*1.0/a[i].t;//����Ͻ�
	while(r-l>1e-5)
	{
		const double mid=(l+r)/2.0;
		if(check(mid))//ע��������ۣ������϶��������½磩
		 l=mid;
		else
		 r=mid;
	}
	ans=l;
}

int main()
{
	input();
	binary();
	printf("%.3f\n",ans);
	return 0;
}
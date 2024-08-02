#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN=500;
int n,m;
struct coffee
{
	int v,t;
	double avr;//算权值t*x-v
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
	 a[i].avr=x*a[i].t-a[i].v;//算每个的权值
    sort(a+1,a+n+1);//从小到大排序
	double tot=0;
	for(int i=1;i<=m;i++)//取前m个小的
	 tot+=a[i].avr;
	return tot<=0;
}

void binary(void)
{
	for(int i=1;i<=n;i++)
	 if(a[i].v*1.0/a[i].t>r)
	  r=a[i].v*1.0/a[i].t;//算出上界
	while(r-l>1e-5)
	{
		const double mid=(l+r)/2.0;
		if(check(mid))//注意分类讨论（这里结合二分求上下界）
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
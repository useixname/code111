#include<bits/stdc++.h>
using namespace std;
int G,n,k,nk,a[200010];
signed main()
{
	cin>>G;
	while(G--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]==k) nk=i;
		}
		int l=1,r=n+1,m=(r+l)/2;
		while(r-l>1)
		{
			m=(r+l)/2;
			if(a[m]<=k) l=m;
			else r=m;
		}
		cout<<"1\n"<<l<<" "<<nk<<"\n"; 
	}
	return 0;
}
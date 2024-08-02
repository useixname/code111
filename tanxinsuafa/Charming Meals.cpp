#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,a[5010],b[5010];
void solve()
{
	cin>>n;
	for(int i=0;i<n;i++)  cin>>a[i];
	for(int i=0;i<n;i++)  cin>>b[i];
	sort(a,a+n),sort(b,b+n);
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		ll res=1e18;
		for(int j=0;j<n;j++)  res=min(res,abs(a[j]-b[(j+i-1)%n]));
		ans=max(ans,res);
	}
	cout<<ans<<endl;
}
int main()
{
	cin>>t;
	while(t--)  solve();
}
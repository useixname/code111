#include<bits/stdc++.h>
using namespace std;
int n,l,ans=0,sna=0;
int main()
{
	cin>>l>>n;
	for(int i=1;i<=n;i++)
	{
		int a;
		cin>>a;
		ans=max(min(l+1-a,a),ans);
		sna=max(max(l+1-a,a),sna);
	}
	cout<<ans<<' '<<sna;
    return 0;
}
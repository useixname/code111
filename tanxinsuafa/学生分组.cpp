#include<bits/stdc++.h>
using namespace std;
int n,a[51],b,c,all,l,r,ans;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	cin>>l>>r;
    for(int i=1;i<=n;i++)
    {
        all+=a[i];
    }
	if(all<n*l||all>n*r)
	{
		cout<<"-1";
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]<l)
		{
			b+=(l-a[i]);
		}
		if(a[i]>r) c+=(a[i]-r);
	}
	cout<<max(b,c);
    return 0;
}
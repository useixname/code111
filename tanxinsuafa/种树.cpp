#include<bits/stdc++.h>
using namespace std;
struct node{
	int l,r,t;
}a[30005];
int n,h,vis[30005],ans=0;
bool cmp(node a,node b)
{
	return a.r<b.r;
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	 memset(vis,0,sizeof(vis));
	 cin>>n>>h;
	 for(int i=1;i<=h;i++)
	 {
	 	cin>>a[i].l>>a[i].r>>a[i].t;
	 }
	 sort(a+1,a+h+1,cmp);
	 for(int i=1;i<=h;i++)
	 {
	 	int cnt=0;
	 	for(int j=a[i].l;j<=a[i].r;j++)
	 	{
	 		if(vis[j]) cnt++; 
		 }
		 if(cnt>=a[i].t) continue;
		 for(int j=a[i].r;j>=a[i].l;j--)
		 {
		 	if(!vis[j])
		 	{
		 		ans++;
		 		cnt++;
		 		vis[j]=1;
			 }
			 if(cnt>=a[i].t) break;
		 }
	 }
	 cout<<ans;
	return 0;
}
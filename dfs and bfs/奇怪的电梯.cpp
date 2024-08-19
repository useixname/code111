#include<bits/stdc++.h>
using namespace std;
int n,a,b,k[201],dis[201];
void dfs(int node,int step){
	dis[node]=step;//一定可以更新
	int v=node-k[node];
	if(1<=v&&step+1<dis[v]/*可以更新在搜索*/)//下
		dfs(v,step+1);
	v=node+k[node];
	if(v<=n&&step+1<dis[v])//上
		dfs(v,step+1);
	return;
}
int main(){
	memset(dis,0x3f,sizeof(dis));
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++)
		cin>>k[i];
	dfs(a,0);
	cout<<(dis[b]==0x3f3f3f3f?-1:dis[b]);
	return 0;
}
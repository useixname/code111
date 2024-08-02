#include<iostream>
using namespace std;
int n,a[40],root[40][40];//a来存储中序遍历，root来存储最大积分的根节点 
long long dp[40][40]={0};//dp[l][r]记录从l区域到r区域最大的加分 

long long dfs(int l,int r){
	if(l>r)return 1;
	if(l==r){
		root[l][r]=l;
		return a[l];
	}
	if(dp[l][r])return dp[l][r];
	for(int i=l;i<=r;i++){
		long long t=dfs(l,i-1)*dfs(i+1,r)+a[i];
		if(dp[l][r]<t)
			dp[l][r]=t;
            root[l][r]=i;
	}
	return dp[l][r];
}

void print(int l,int r){
	if(l>r)return;
	cout<<root[l][r]<<" ";
	print(l,root[l][r]-1);
	print(root[l][r]+1,r);
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        dp[i][i]=a[i];
        root[i][i]=i;
    }
    cout<<dfs(1,n)<<'\n';
    print(1,n);
    return 0;
}
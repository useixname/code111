#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200;
int n,m;
int a[N];
int tr[4*N];
int lowbit(int x){
	return x&(-x);
}
int sum(int x){
	int res=0;
	for(int i=x;i;i-=lowbit(i))res+=tr[i];
	return res;
}
void add(int x,int c){
	for(int i=x;i<=n;i+=lowbit(i))tr[i]+=c;
}
bool cheek(int x,int s){
	if(sum(x)>=s)return true;
	else return false;
}
void show(){
    for(int i=1;i<=n;i++){
        cout<<sum(i)<<" ";
    }
    cout<<'\n';
}
void sove(){
	cin>>n>>m;
	int now=1;
	int op=n;
	for(int i=1;i<=n;i++)add(i,1);
    show();
	while(op){
		now=(now+m-1-1)%op+1;
		int l=1,r=n;
		while(l<r){
			int mid=l+r>>1;
			if(cheek(mid,now))r=mid;
			else l=mid+1;
		}
		cout<<l<<" ";   
		add(l,-1);
        //show();
		op--;
	}
	
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(),cout.tie();
	int t=1;
	while(t--){
		sove();
	}
	return 0;
}
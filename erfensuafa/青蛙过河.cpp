#include <bits/stdc++.h>
using namespace std;

int maxn=0x3f3f3f3f;
const int N=1e5+10;
int a[N],sum[N],ans;
int n,k;

bool chk(int l){
	int cnt=maxn;
    for(int i=l;i<=n-1;i++){
    cnt=min(cnt,sum[i]-sum[i-l]);
  }
  return cnt>=2*k;
}
int main()
{
  cin>>n>>k;
  for(int i=1;i<=n-1;i++){
    cin>>a[i];
    sum[i]=sum[i-1]+a[i];
  }
  int l=1,r=n;
  while(l<r){
    int mid=(l+r)>>1;
    if(chk(mid)){
      ans=mid;
      r=mid;
    }
    else{
      l=mid+1;
    }
  }
  cout<<ans;
  return 0;
}
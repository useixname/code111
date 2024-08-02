#include <iostream>
using namespace std;

const int N=21e5+10;
int a[N];
long long sum[N];
int main()
{
  int n;
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>a[i];
    sum[i]=sum[i-1]+a[i];
  }
  long long ans=0;
  for(int i=1;i<=n;i++){
    ans+=a[i]*(sum[n]-sum[i]);
  }
  cout<<ans;
  return 0;
}
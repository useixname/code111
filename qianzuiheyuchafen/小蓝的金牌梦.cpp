#include <iostream>
#include<bits/stdc++.h>
using namespace std;
bool mm(long long num)
{
  for(int i=2;i*i<=num;i++)
  {
    if(num%i==0)
    {
      return false;
    }
  }
  return true;
}
int main()
{
  long long n;
  cin>>n;
  vector<long long> arr(n+1);
  for(int i=1;i<=n;i++)
  {
    cin>>arr[i];
    arr[i]+=arr[i-1];
  }
  long long res=INT_MIN;
  for(int i=2;i<=n;i++)
  {
    if(mm(i))
    {
      for(int j=i;j<=n;j++)
      {
        res=max(res,arr[j]-arr[j-i]);
      }
    }
  }
  cout<<res;
  return 0;
}
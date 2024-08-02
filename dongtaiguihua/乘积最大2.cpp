#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=100;
int n,K;
string s;
int a[maxn];
struct lxt
{
    int len;
    int ans[maxn];
}dp[maxn/10][maxn];

lxt cal(lxt x,int l,int r)
{
    lxt Ans,y;
    memset(Ans.ans,0,sizeof(Ans.ans));
    memset(y.ans,0,sizeof(y.ans));
    y.len=r-l+1;
    for(int i=r;i>=l;--i) y.ans[r-i+1]=a[i];
    int l1=x.len,l2=y.len,ll;
    for(int i=1;i<=l1;++i)
      for(int j=1;j<=l2;++j)
          Ans.ans[i+j-1]+=x.ans[i]*y.ans[j];
    ll=l1+l2-1;      
    for(int i=1;i<=ll;++i)
    {
        Ans.ans[i+1]+=Ans.ans[i]/10;
        Ans.ans[i]=Ans.ans[i]%10;
    }
    if(Ans.ans[ll+1]) ll++;
    Ans.len=ll;
    return Ans;
}
lxt cmp(lxt x,lxt y)
{
    int lx=x.len,ly=y.len;
    if(lx<ly) return y;
    if(lx>ly) return x;
    for(int i=lx;i>=1;--i)
    {
        if(x.ans[i]>y.ans[i]) return x;
        if(x.ans[i]<y.ans[i]) return y;
    }
    return x; 
}
int main()
{
    scanf("%d%d",&n,&K);
    cin>>s;
    for(int i=1;i<=n;++i) a[i]=s[i-1]-'0';
    for(int i=1;i<=n;++i)
      for(int j=i;j>=1;--j)
        dp[0][i].ans[++dp[0][i].len]=a[j];
    for(int i=2;i<=n;++i)
      for(int k=1;k<=min(K,i-1);++k)
        for(int j=k;j<i;++j)
          dp[k][i]=cmp(dp[k][i],cal(dp[k-1][j],j+1,i));
    for(int i=dp[K][n].len;i>=1;--i)
      printf("%d",dp[K][n].ans[i]);
    return 0;
}
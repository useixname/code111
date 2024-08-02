/*
DFS+¸ô°å·¨£º
*/
#include<iostream>
using namespace std;
bool st[10];
int a[10];
int n;
int ans;

int qmi(int a,int b)
{
  int res=1;
  while(b)
  {
    if(b&1)res*=a;
    a*=a;
    b>>=1;
  }
  return res;
}

int cal(int x,int y)
{
  int res=0;
  for(int i=0;i<y-x+1;i++)
  {
    res+=a[x+i]*qmi(10,i);
  }
  return res;
}

void dfs(int u)
{
  if(u>=9)
  {
    for(int i=1;i<9;i++)
    {
      for(int j=i;j<8;j++)
      {
          int x1=cal(0,i-1);
          int x2=cal(i,j);
          int x3=cal(j+1,8);
          if(x2%x3==0&&n==(x1+x2/x3))
          {
            printf("%d=%d+%d/%d\n",n,x1,x2,x3);
            ans++;
          }
      }
    }
  }

  for(int i=1;i<=9;i++)
  {
    if(!st[i])
    {
      st[i]=true;
      a[u]=i;
      dfs(u+1);
      st[i]=false;
    }
  }
} 

int main()
{
  cin>>n;
  dfs(0);
  cout<<ans<<endl;
  return 0;
}

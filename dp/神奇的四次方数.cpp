#include<cstdio>
#include<cstring>
#include<cmath>
#define min(x,y) (x<y?x:y)
const int MAXN=200010;
int s[MAXN],f[MAXN];
int m;

int main()
{
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
        f[i]=1e8;
    // int n=ceil(sqrt(sqrt(m))+1);
    // for(int i=1;i<=n;i++)
    //     s[i]=i*i*i*i;
    int n=1;
    while(s[n-1]<=m) s[n]=n*n*n*n,n++;
    n-=1;
    for(int i=1;i<=n;i++)
        for(int j=s[i];j<=m;j++)
            f[j]=min(f[j],f[j-s[i]]+1);
    printf("%d\n",f[m]);
}
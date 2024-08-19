#include <cstdio>
#include <cstring>
using namespace std;

const int MAXM=60;
int a[MAXM],b[MAXM],sum[MAXM],n,m,c;
int f[MAXM][MAXM][2];

int min(int a,int b)
{return a<b?a:b;}

int max(int a,int b)
{return a>b?a:b;}

int main()
{
    scanf("%d%d",&n,&c);
    memset(f,127,sizeof(f));
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i],&b[i]),sum[i]=sum[i-1]+b[i];
    }
    f[c][c][0]=f[c][c][1]=0;
    for(int l=2;l<=n;l++)
    for(int i=1;i+l-1<=n;i++)
    {
        int j=i+l-1;
        f[i][j][0]=min(f[i+1][j][0]+(a[i+1]-a[i])*(sum[i]+sum[n]-sum[j]),
                f[i+1][j][1]+(a[j]-a[i])*(sum[i]+sum[n]-sum[j]));
        f[i][j][1]=min(f[i][j-1][0]+(a[j]-a[i])*(sum[i-1]+sum[n]-sum[j-1]),
                f[i][j-1][1]+(a[j]-a[j-1])*(sum[i-1]+sum[n]-sum[j-1]));
    }
    int ans=min(f[1][n][0],f[1][n][1]);
    printf("%d",ans);
    return 0;
}
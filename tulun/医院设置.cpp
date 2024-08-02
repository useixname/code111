#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define big 100000007
int p[101],dis[101][101],sum;
int n,l,r;
using namespace std;
int main()
{
    cin>>n;
    memset(dis,big,sizeof(dis));
    for(int i=1;i<=n;i++)
    {
        dis[i][i]=0;
        cin>>p[i];
        cin>>l>>r;
        if(l>0) dis[i][l]=1;dis[l][i]=1;
        if(r>0) dis[i][r]=1;dis[r][i]=1;
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(dis[i][j]>dis[i][k]+dis[k][j]) dis[i][j]=dis[i][k]+dis[k][j];
            }
        }
    }
    int minn=big;
    for(int i=1;i<=n;i++)
    {
        sum=0;
        for(int j=1;j<=n;j++)
        {
            sum+=p[j]*dis[i][j]; 
        }
        if(minn>sum) minn=sum;
    }
    cout<<minn<<endl;
    return 0;
}
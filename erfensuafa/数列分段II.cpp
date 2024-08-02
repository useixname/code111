#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],ans;
inline bool check(int x)
{
    int tot=0,num=0;
    for(int i=1;i<=n;i++)
    {
        if(tot+a[i]<=x)tot+=a[i];
        else tot=a[i],num++;
    }
    return num<m;
}
int main()
{
    int l=0,r=0,mid;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),l=fmax(l,a[i]),r+=a[i];
    l-=1,r+=1;
    while(l+1<r)
    {
        mid=l+r>>1;
        if(check(mid))r=mid;
        else l=mid;
    }
    cout<<r;
    return 0;
}
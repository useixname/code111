#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h,k;
    scanf("%d%d",&h,&k);
    long long ans=0;
    ans=(k+1)*(1<<h);
    printf("%lld\n",ans);
    return 0;
} 
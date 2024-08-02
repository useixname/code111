#include<iostream>
#include<cstring>
#include<cstdio> 
using namespace std;
typedef long long ll;
int n,m;
ll diff[1000011],rest[1000011],r[1000011],l[1000011],d[1000011];

void insert(int c,int l,int r){
    diff[l]+=c;
    diff[r+1]-=c; 
}

bool chk(int x)
{
    memset(diff,0,sizeof(diff));
    for(int i=1;i<=x;i++)
    {
        insert(d[i],l[i],r[i]);
    }
    for(int i=1;i<=n;i++)
    {
        diff[i]=diff[i-1]+diff[i];
        if(diff[i]>rest[i])return 0;
    }
    return 1;
}

int main()
{
    
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&rest[i]);
    for(int i=1;i<=m;i++)scanf("%d%d%d",&d[i],&l[i],&r[i]);
    int begin=1,end=m; 
    if(chk(m)){
        cout<<"0";
        return 0;
    }
    while(begin<end)
    {
        int mid=(begin+end)/2;
        if(chk(mid))begin=mid+1;
        else end=mid;
    }
    cout<<"-1"<<endl<<begin;
    return 0;
}
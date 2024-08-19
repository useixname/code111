#include<bits/stdc++.h>
using namespace std;
const int N=110;
const int INF=0x3f3f3f3f;
const int n9[9]={9,81,729,6561,59409,531441,4782969,43046721,387420489};
int a[N];
int n,m;
int minans=INF,maxans=0;

int mod10(int x){
    return (x%10+10)%10;
}

void dfs(int d,int u,int s){
    int sum=0;
    if(s>=minans&&s*n9[m-d]<=maxans){
        return;
    }
    if(m==d){
        for(int i=u;i<=n;i++){
            sum+=a[i];
        }
        minans=fmin(minans,s*mod10(sum));
        maxans=fmax(maxans,s*mod10(sum));
        return;
    }
    for(int i=u;i<=n-m+d;i++){
        sum+=a[i];
        dfs(d+1,i+1,s*mod10(sum));
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i+n]=a[i];
    }
    for(int i=1;i<=n;i++){
        dfs(1,1,1);
        for(int j=1;j<=2*n;j++){
            a[j]=a[j+1];
        }
    }
    printf("%d\n%d",minans,maxans);
    return 0;
}
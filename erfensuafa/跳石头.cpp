#include<bits/stdc++.h>
using namespace std;
const int N=5e4+10;
int a[N],d[N];
int l,n,m;

bool chk(int x){
    d[N]=a[N];
    int cnt=0;
    int i=0,j=1;
    while(j<=n+1){
        if(a[j]-a[i]<x){
            cnt++;
            j++;
        }
        if(a[j]-a[i]>=x){
            i=j;
            j++;
        }
    }
    return cnt<=m;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>l>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    a[n+1]=l;
    int l=0,r=1e9+1;
    while(l+1<r){
        int mid=l+r>>1;
        if(chk(mid)) l=mid;
        else r=mid;
    }
    cout<<l;
    return 0;
}
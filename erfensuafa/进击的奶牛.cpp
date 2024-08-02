#include<bits/stdc++.h>
using namespace std;
const int N=1e9+10;
int a[N];
int n,m;

bool chk(int mid){
    int k=1,t=1;
    for(int i=1;i<=n;i++){
        if(a[i]-a[t]>=mid){
            t=i;
            k++;
        }
    }
    return k>=m;
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int l=0,r=N;
    while(l+1<r){
        int mid=(l+r)>>1;
        if(chk(mid)){
            l=mid;
        }
        else{
            r=mid;
        }
    }
    cout<<l;
    return 0;
}
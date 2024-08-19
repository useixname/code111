#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n;
int a[N],b[N];
long long ans=0;
void msort(int l,int r){
    if(l==r) return;
    int m=l+r>>1;
    msort(l,m);msort(m+1,r);//²ð·Ö

    int i=l,j=m+1,k=l;//ºÏ²¢
    while(i<=m&&j<=r){
        if(a[i]<=a[j]) b[k++]=a[i++];
        else b[k++]=a[j++],ans+=m-i+1;
    }
    while(i<=m){
        b[k++]=a[i++];
    }
    while(j<=r){
        b[k++]=a[j++];
    }
    for(int i=l;i<=r;i++){
        a[i]=b[i];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    msort(1,n);
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    cout<<'\n'<<ans;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n;
int a[N],b[N];

void msort(int l,int r){
    if(l==r) return;
    int m=l+r>>1;
    msort(l,m);msort(m+1,r);//²ð·Ö

    int i=l,j=m+1,k=l;//ºÏ²¢
    while(i<=m&&j<=r){
        if(a[i]<=a[j]) b[k++]=a[i++];
        else b[k++]=a[j++];
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
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,k;
int a[N];

int qsort(int l,int r){
    if(l==r) return a[l];
    int i=l-1,j=r+1,x=a[(l+r)>>1];
    while(i<j){
        do i++; while(a[i]<x);
        do j--; while(a[j]>x);
        if(i<j) swap(a[i],a[j]);
    }
    if(k<=j) return qsort(l,j);
    else return qsort(j+1,r);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<qsort(1,n)<<'\n';
    return 0;
}
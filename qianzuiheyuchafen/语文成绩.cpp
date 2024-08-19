#include<bits/stdc++.h>
using namespace std;
const int N=5e6+10;
int a[N],d[N];
int n,q;

void insert(int l,int r,int c){
    d[l]+=c;
    d[r+1]-=c;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        insert(i,i,a[i]);
    }
    while(q--){
        int x,y,z;
        cin>>x>>y>>z;
        insert(x,y,z);
    }
    for(int i=1;i<=n;i++){
        d[i]+=d[i-1];
    }
    sort(d+1,d+n+1);
    cout<<d[1];
    return 0;
}
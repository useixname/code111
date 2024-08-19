#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
int dp[N],v[N];
int x,y,n,q,m;
struct node{
    int k,s;
}w[N];
int main(){
    ios_base::sync_with_stdio(0);
    cin>>x>>y;
    int k=y/x;
    cin>>n>>q;
    for(int i=1;i<=q;i++){
        int t;
        cin>>t;
        v[i]=k*t;
    }
    for(int i=1;i<=n;i++){
        cin>>w[i].k>>w[i].s;
    }
    cin>>m;
    for(int i=1;i<=n;i++){
        for(int j=m;j>=v[w[i].k];j--){
            dp[j]=max(dp[j-v[w[i].k]]+w[i].s,dp[j]);
        }
    }
    cout<<dp[m];
    return 0;
}
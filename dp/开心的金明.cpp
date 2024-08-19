#include<bits/stdc++.h>
using namespace std;
const int N=30;
typedef pair<int,int>PII;
vector<PII>a;
int v[N],w[N],dp[100000010];
int n,m;

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>v[i]>>w[i];
    }
    for(int i=1;i<=m;i++){
        for(int j=n;j>=v[i];j--){
            dp[j]=max(dp[j],dp[j-v[i]]+v[i]*w[i]);
        }
    }
    cout<<dp[n];
    return 0;
}
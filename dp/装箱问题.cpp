#include<bits/stdc++.h>
using namespace std;
const int N=21e4+10;
int w[35],dp[N];
int v,n;

int main(){
    cin>>v>>n;
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=v;j>=w[i];j--){
            dp[j]=max(dp[j],dp[j-w[i]]+w[i]);
        }
    }
    cout<<v-dp[v];
    return 0;
}
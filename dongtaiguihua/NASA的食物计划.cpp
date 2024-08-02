#include<bits/stdc++.h>
using namespace std;
int h1,t1,n;
int h[500],t[500],k[500],dp[500][500];

int main(){
    ios_base::sync_with_stdio(0);
    cin>>h1>>t1>>n;
    for(int i=1;i<=n;i++){
        cin>>h[i]>>t[i]>>k[i];
    }
    for(int l=1;l<=n;l++){
        for(int i=h1;i>=h[l];i--){
            for(int j=t1;j>=t[l];j--){       
               dp[i][j]=max(dp[i-h[l]][j-t[l]]+k[l],dp[i][j]);
            }
        }
    }
    cout<<dp[h1][t1];
    return 0;
}
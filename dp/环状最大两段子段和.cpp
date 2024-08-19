#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=4e5+10;
int a[N],dp[N][N];
int n;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i+n]=a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i+n-1;j<=2*n-1;j++){
            for(int k=i;k<j;k++){
                dp[i][j]=max(dp[i][k]+dp[k+1][j],dp[i][j]);
            }
        }
    }
}
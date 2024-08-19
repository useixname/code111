#include <iostream>
#include <cstdio>
using namespace std;
int n, f[100005], a[100005];
double c, k, w, dp[100005];
int main(){
    cin>>n>>k>>c>>w;
    for(int i=1; i<=n; i++)
        scanf("%d %d", &f[i], &a[i]);
    for(int i=n; i>=1; i--){
        if(f[i]==1)    dp[i] = max(dp[i+1], a[i]+dp[i+1]*(1-0.01*k));
        else           dp[i] = max(dp[i+1],-a[i]+dp[i+1]*(1+0.01*c));
    }
    printf("%.2lf", dp[1]*w);
    return 0;
}
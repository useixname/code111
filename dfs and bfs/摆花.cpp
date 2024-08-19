#include<bits/stdc++.h>
using namespace std;
const int maxn=105, mod = 1000007;
int n, m, a[maxn];
int dfs(int x,int k)
{
    if(k > m) return 0;
    if(k == m) return 1;
    if(x == n+1) return 0;
    int ans = 0;
    for(int i=0; i<=a[x]; i++) ans = (ans + dfs(x+1, k+i))%mod;
    return ans;
}
int main()
{
    cin>>n>>m;
    for(int i=1; i<=n; i++) cin>>a[i];
    cout<<dfs(1,0)<<endl;
    return 0;
}
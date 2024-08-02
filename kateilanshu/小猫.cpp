#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
long long f[100010];
int n;

int main(){
    cin>>n;
    f[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=i-1;j++){
            f[i]+=f[j]*f[i-1-j];
            f[i]%=mod;
        }
    }
    cout<<f[n];
    return 0;
}
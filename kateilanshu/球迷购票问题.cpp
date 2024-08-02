#include<bits/stdc++.h>
using namespace std;

int n;
long long f[25];

int main(){
    cin>>n;
    f[0]=1;
    for(int i=0;i<=n-1;i++){
        f[i+1]=(f[i]*(2*(2*i+1)))/(i+2);
    }
    cout<<f[n];
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int n;
long long f[20]={1};

int main(){
    cin>>n;
    for(int i=0;i<=n-1;i++){
        f[i+1]=(2*(2*i+1)*f[i])/(i+2);
    }
    cout<<f[n];
    return 0;
}
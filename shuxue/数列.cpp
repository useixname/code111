#include<bits/stdc++.h>
using namespace std;
#define int long long
int k,n;
int a[15];


signed main(){
    ios_base::sync_with_stdio(0);
    cin>>k>>n;
    int t=0,ans=0;
    while(n){
        int m=n%2;
        a[t++]=m;
        n/=2;
    }
    for(int i=0;i<=t;i++){
        if(a[i]){
            ans+=pow(k,i);
        }
    }
    cout<<ans;
    return 0;
}
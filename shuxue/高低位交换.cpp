#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[33];

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    int len=1,ans=0;
    while(n){
        a[len]=n%2;
        n/=2;
        if(n==0) break;
        len++;
    }
    for(int i=1;i<=32;i++){
        if(i<=16){
            ans+=a[i]*pow(2,i+15);
        }
        else{
            ans+=a[i]*pow(2,i-17);
        }
    }
    cout<<ans;
    return 0;
}
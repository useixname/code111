#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;


int decompose(int x){
    int ans;
    for(int i=2;i*i<=x;i++){
        while(x%i==0){
            ans=i;
            x/=i;
        }
    }
    if(x>1){
        ans=max(x,ans);
    };
    return ans;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    cout<<decompose(n);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
typedef long long ll;
ll a[N],m;
int n,ans=0;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int i=1,sum=0;
    while(i<=n){
        sum+=a[i];
        // if(i==n&&sum<=m){
        //     ans++;
        //     break;
        // }
        if(sum>m){
            sum=a[i];
            ans++;
        }
        if(i==n&&sum<=m){
            ans++;
            break;
        }
        i++;
    }
    cout<<ans;
    return 0;
}
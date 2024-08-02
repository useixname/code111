#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,a[N],dp1[N],dp2[N],ans=0;

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        dp1[i]=1;
        dp2[i]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if(a[j]<a[i]){
                dp1[i]=max(dp1[i],dp1[j]+1);
            }
        }
    }
    for(int i=n;i>=1;i--){
        for(int j=n;j>i;j--){
            if(a[j]<a[i]){
                dp2[i]=max(dp2[i],dp2[j]+1);
            }
        }
    }
    for(int i=1;i<=n;i++){
        ans=max(ans,dp1[i]+dp2[i]-1);
    }
    cout<<n-ans;
    return 0;
}
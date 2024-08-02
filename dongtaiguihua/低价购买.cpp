#include<iostream>
#include <string.h>
using namespace std;

int main(){
    long long ans=0,max=1;
    int n;
    cin>>n;
    long long a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    long long dp[n],cnt[n];
    memset(dp,0,sizeof(dp));
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<n;i++){
        dp[i]=1;
        cnt[i]=1;
        for(int j=0;j<i;j++){
            if(a[j]>a[i]){
                if(dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    cnt[i]=cnt[j];
                }
                else if(dp[j]+1==dp[i]){
                    cnt[i]+=cnt[j];
                }
            }
        }
        if(dp[i]>max){
            max=dp[i];
            ans=cnt[i];
        }
        else if(dp[i]==max){
            ans+=cnt[i];
        }
    }
    cout<<max<<" "<<ans;
}
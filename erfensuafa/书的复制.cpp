#include<bits/stdc++.h>
using namespace std;
const int N=505;
long long a[N],sum[N];
int n,k;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    long long s=sum[n];
    int t=k,d=0;
    int st=1;
    for(int i=1;i<=k-1;i++){
        long long x=(sum[st]+sum[n])/t;
        int index=lower_bound(sum+1,sum+n+1,x) - sum;
        while(sum[index]>x){
            index--;
        }
        int et=index;
        cout<<st<<" "<<et<<'\n';
        st=et+1;
        //d=x;
        //s-=x;
        t--;
    }
    cout<<st<<" "<<n;
    return 0;
}
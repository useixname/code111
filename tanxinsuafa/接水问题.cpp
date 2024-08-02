#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int n,m;
int a[N];

int main(){
    int ans=0;
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int i=m+1;
    while(i<=n+1){
        sort(a+1,a+m+1);
        if(i==n+1){
            ans+=a[n];
            break;
        }
        int x=a[1];
        ans+=x; 
        for(int j=1;j<=m;j++){
            a[j]-=x;
        }
        a[1]=a[i];
        i++;
    }
    cout<<ans;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

const int N=21e5+10;
int a[N],b[N],ans=-2147483647;

int n;

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i==1){
            b[i]=a[i];
        }
        else{
            b[i]=max(b[i-1]+a[i],a[i]);
        }
        ans=max(ans,b[i]);
    }
    cout<<ans;
}
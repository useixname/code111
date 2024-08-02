#include<bits/stdc++.h>
using namespace std;
const int N=3e4+10;
int a[N];



int main(){
    int m,n,ans=0;
    ios_base::sync_with_stdio(0);
    cin>>m>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int i=1,j=n;
    while(i<=j){
        if(i==j){
            break;
        }
        if(a[i]+a[j]<=m){
            ans++;
            i++;
            j--;
        }
        else{
            j--;
        }
    }
    cout<<n-ans;
    return 0;
}
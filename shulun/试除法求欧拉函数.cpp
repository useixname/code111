#include<bits/stdc++.h>
using namespace std;
int n;

int phi(int n){
    int ret=n;
    for(int i=2;i*i<=n;i++){
       ret=ret/i*(i-1);
       while(n%i==0){
        n/=i;
       }
    }
    if(n>1){
        ret=ret/n*(n-1);
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    cout<<phi(n);
}
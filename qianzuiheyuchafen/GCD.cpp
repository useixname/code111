#include<bits/stdc++.h>
using namespace std;
int n,ans=0;

int gcd(int n,int m){
    if(n%m==0){
        return m;
    }
    return gcd(m,n%m);
}

bool is_prime(int n){
    if(n==1){
        return false;
    }
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

int find(int n){
    int ans=n;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            ans/=i*(i-1);
            while(n%i==0){
                n/=i;
            }
        }
    }
    if(n>1){
       ans/=n*(n-1);
    }
    return ans;
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        // for(int j=i;j<=n;j++){
        //     if(is_prime(gcd(i,j))){
        //         if(i!=j){
        //             ans+=2;
        //         }
        //         else{
        //             ans+=1;
        //         }
        //     }
        // }
        ans+=find(i);
    }
    cout<<ans;
    return 0;
}
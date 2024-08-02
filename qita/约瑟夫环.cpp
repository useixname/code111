#include<bits/stdc++.h>
using namespace std;

int n,k;

int f(int n,int m){
    return n==1?1:(f(n-1,m)+m-1)%n+1;
}
int main(){
    cin>>n>>k;
    cout<<f(n,k);
}
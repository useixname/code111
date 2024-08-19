#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=4e5+10;
int a[N];
int n;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i+n]=a[i];
    }
    
}
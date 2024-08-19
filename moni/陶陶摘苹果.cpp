#include<bits/stdc++.h>
using namespace std;
int a[11];
int n;

int main(){
    ios_base::sync_with_stdio(0);
    for(int i=1;i<=10;i++){
        cin>>a[i];
    }
    cin>>n;
    sort(a+1,a+10+1);
    int x=upper_bound(a+1,a+11,n+30)-a;
    if(a[x]<=n+30){
        cout<<10;
    }
    else{
        cout<<x-1;
    }
    return 0;
}
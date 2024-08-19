#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int a[N];
int l,m,ans=0;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>l>>m;
    while(m--){
        int x,y;
        cin>>x>>y;
        for(int i=x;i<=y;i++){
            a[i]=1;
        }
    }
    for(int i=0;i<=l;i++){
        if(!a[i]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
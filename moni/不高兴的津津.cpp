#include<bits/stdc++.h>
using namespace std;

int maxn=8,ans;

int main(){
    ios_base::sync_with_stdio(0);
    for(int i=1;i<=7;i++){
        int x,y;
        cin>>x>>y;
        if(x+y>maxn){
            maxn=x+y;
            ans=i;
        }
    }
    cout<<ans;
    return 0;
}
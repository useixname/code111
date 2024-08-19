#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
int n;
map<int,int>m;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int cnt=0;
    for(int i=1;i<=n;i++){
        cnt++;
        if(a[i]!=a[i+1]){
            cout<<a[i]<<" "<<cnt<<'\n';
            cnt=0;
        }
    }
    return 0;
}
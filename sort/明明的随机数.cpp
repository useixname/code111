#include<bits/stdc++.h>
using namespace std;
const int N=105;
int a[N];
int n;
set<int> s;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s.emplace(a[i]);
    }
    cout<<s.size()<<'\n';
    for(auto i=s.begin();i!=s.end();i++){
        auto t=*i;
        cout<<t<<" ";
    }
    return 0;
}
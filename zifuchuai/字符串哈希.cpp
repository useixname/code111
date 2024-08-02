#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
const int P=131;
const int N=1e5+10;
ull p[N],h[N],ans[N];
string s[N];

void init(string s){
    p[0]=1,h[0]=0;
    for(int i=1;i<=s.length();i++){
        p[i]=p[i-1]*P;
        h[i]=h[i-1]*P+s[i];
    }
}

ull get(int l,int r){
    return h[r]-h[l-1]*(p[r-l+1]);
}

bool chk(int l1,int r1,int l2,int r2){
    return get(l1,r1)==get(l2,r2);
}

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        init(s[i]);
        ans[i]=get(1,s[i].length());
    }
    int ret=0;
    sort(ans+1,ans+1+n);
    for(int i=1;i<=n;i++){
        if(ans[i]!=ans[i-1]){
            ret++;
        }
    }
    cout<<ret;
    return 0;
}
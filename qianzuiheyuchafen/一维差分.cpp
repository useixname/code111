#include<bits/stdc++.h>
using namespace std;

const int N=21e5+10;
int diff[N]={0};

int main(){
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    for(int i=0;i<m;i++){
        int l,r,k;
        cin>>l>>r>>k;
        k%=26;
        diff[l-1]+=k;
        diff[r]-=k;
    }
    for(int i=1;i<n;i++){
        diff[i]+=diff[i-1];
    }
    for(int i=0;i<n;i++){
        //int offset = s[i] - 'a';
        s[i] = 'a'+(s[i] - 'a' + diff[i]) % 26;
        //s[i] = 'a' + offset;
    }
    cout<<s;
}
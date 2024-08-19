#include<bits/stdc++.h>
using namespace std;
int m,s;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>m;
    int l=1,r=1;
    while(l<=m/2&&l<=r){
        while(s<m) s+=r,r++;
        while(s>m) s-=l,l++;
        if(s==m) s-=l,l++,cout<<l-1<<" "<<r-1<<'\n';
    }
    return 0;
}
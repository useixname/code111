#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int n;

struct node{
    int a,b,c,s,k;
    bool operator<(const node & pa) const{
        if(s==pa.s){
            if(a==pa.a){
                return k<pa.k;
            }
            else{
                return a>pa.a;
            }
        }
        return s>pa.s;
    }
}num[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>num[i].a>>num[i].b>>num[i].c;
        num[i].s=num[i].a+num[i].b+num[i].c;num[i].k=i;
    }
    sort(num+1,num+n+1);
    for(int i=1;i<=5;i++){
        cout<<num[i].k<<" "<<num[i].s<<'\n';
    }
    return 0;
}
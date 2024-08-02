#include<bits/stdc++.h>
using namespace std;

const int N=1e3+10;
int n,ans=1;
struct node{
    int st,et;
}act[N];

bool cmp(node &x,node &y){
    if(x.et!=y.et){
        return x.et<y.et;
    }
    return x.st<y.st;
}
/*4
1 3
4 6
2 5
1 7

1 3
2 5
4 6
1 7*/
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>act[i].st>>act[i].et;
    }
    sort(act+1,act+n+1,cmp);
    int last=act[1].et;
    for(int i=2;i<=n;i++){
        if(act[i].st>=last){
            ans++;
            last=act[i].et;
        }
    }
    cout<<ans;
}
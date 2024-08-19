#include<bits/stdc++.h>
using namespace std;
int n,k;
set<int>s;

int main(){
    ios_base::sync_with_stdio(0);
    // FILE * fp= fopen("P1138_9.in","r");
    // FILE * fo= fopen("P1138_9.out","w");
    // fscanf(fp,"%d %d",&n,&k);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        // fscanf(fp,"%d ",&x);
        s.emplace(x);
    }
    if(k>=s.size()){
        cout<<"NO RESULT";
    }
    else{
        auto it = s.begin();
        advance(it, k-1);
        cout<<*it;
    }
    return 0;
}
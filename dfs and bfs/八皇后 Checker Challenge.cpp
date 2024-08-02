#include<bits/stdc++.h>
using namespace std;
int n,mp[15],cnt=0,ans=0;

bool chk(int row,int col){
    for(int i=1;i<row;i++){
        if(mp[i]==col){
            return false;
        }
        if(abs(i-row)==abs(mp[i]-col)){
            return false;
        }
    }
    return true;
}

void dfs(int row){
    if(row==n+1){
        if(cnt<3){
            for(int i=1;i<=n;i++){
                cout<<mp[i]<<" ";
            }
            cout<<'\n';
            cnt++;
        }
        ans++;
        return;
    }
    for(int col=1;col<=n;col++){
        if(chk(row,col)){
            mp[row]=col;
            dfs(row+1);
            mp[row]=0;
        }
    }
}

int main(){
    cin>>n;
    dfs(1);
    cout<<ans;
    return 0;
}
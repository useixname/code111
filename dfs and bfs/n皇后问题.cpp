#include<bits/stdc++.h>
using namespace std;

const int N=35;

int n,m[N],ans=0;


bool chk(int row,int col){
    for(int i=0;i<row;i++){
        if(m[i]==col){
            return false;
        }
        if(abs(i-row)==abs(m[i]-col)){
            return false;
        }
    }
    return true;
}

void dfs(int row){
    if(row==n){
        ans++;
        return;
    }
    for(int col=0;col<n;col++){
        if(chk(row,col)){
            m[row]=col;
            dfs(row+1);
            m[row]=0;
        }
    }
}

int main(){
    cin>>n;
    dfs(0);
    cout<<ans;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int net[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int vis[N][N];
char a[N][N];
int n,m,ans=0;

bool d(int i,int j){
	int c=0;
	if(a[i][j]=='#')c++;
	if(a[i+1][j]=='#')c++;
	if(a[i][j+1]=='#')c++;
	if(a[i+1][j+1]=='#')c++;
	if(c==3)return true;
	return false;
}

void dfs(int x,int y){
    a[x][y]='.';
    for(int i=0;i<4;i++){
        int tx=x+net[i][0],ty=y+net[i][1];
        if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&a[tx][ty]=='#'){
            dfs(tx,ty);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i<n&&j<m&&d(i,j)){
                printf("Bad placement.");
                return 0;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]=='#'){
                ans++;
                dfs(i,j);
            }
        }
    }
    printf("There are %d ships.",ans);
    return 0;
}
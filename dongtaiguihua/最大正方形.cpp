#include<bits/stdc++.h>
using namespace std;
int dp[105][105];
vector<vector<int>>matrix(105);
int n,m;
class Solution {
public:
    int maximalSquare(vector<vector<int>>& matrix) {
        int ret=0; 
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            if(matrix[i-1][0]==1){
                ret=1;
                dp[i][1]=1;
            }
        }
        for(int i=1;i<=m;i++){
            if(matrix[0][i-1]==1){
                ret=1;
                dp[1][i]=1;
            }
        }
        for(int i=2;i<=n;i++){
            for(int j=2;j<=m;j++){
                if(matrix[i-1][j-1]==0){
                    dp[i][j]=0;
                }
                else{
                    dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
                    ret=max(ret,dp[i][j]);
                }
            }
        }
        return ret;
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x;
            cin>>x;
            matrix[i].push_back(x);
        }
    }
    Solution s;
    cout<<s.maximalSquare(matrix);
    return 0;
}

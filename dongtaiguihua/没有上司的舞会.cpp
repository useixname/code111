#include <iostream>
#include <vector>
#include <algorithm>
#define N 6005
using namespace std;
int n;
bool visited[N];
vector<int> T[N];
int dp[N][2]; // 从结点i往下所获最大value
// dp[i][0]表示i不参加时子树的maxValue，dp[i][1]表示i参加时子树的maxValue


void dfs(int k) { // 给定结点k，求以k为root的最大收益
    if (visited[k]) return ;
    visited[k] = true;
    for (int i = 0; i < T[k].size(); ++i) {
        int v = T[k][i];
        dfs(v);
        dp[k][0] += max(dp[v][0],dp[v][1]);
        dp[k][1] += dp[v][0];
    }
}


int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> dp[i][1];
    }
    bool tmp[N] = {0};
    for (int i = 1; i <= n-1; ++i) {
        int l,k;
        cin >> l >> k;
        T[k].push_back(l);
        tmp[l] = 1; // 是孩子结点，标记为1
    }
    for (int i = 1; i <= n; ++i) {
        if (tmp[i] == 0) { // 寻找唯一的根节点，找到之后dfs
            dfs(i);
            cout << max(dp[i][0],dp[i][1]) << "\n";
            break;
        }
    }
    return 0;
}
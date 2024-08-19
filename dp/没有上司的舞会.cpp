#include <iostream>
#include <vector>
#include <algorithm>
#define N 6005
using namespace std;
int n;
bool visited[N];
vector<int> T[N];
int dp[N][2]; // �ӽ��i�����������value
// dp[i][0]��ʾi���μ�ʱ������maxValue��dp[i][1]��ʾi�μ�ʱ������maxValue


void dfs(int k) { // �������k������kΪroot���������
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
        tmp[l] = 1; // �Ǻ��ӽ�㣬���Ϊ1
    }
    for (int i = 1; i <= n; ++i) {
        if (tmp[i] == 0) { // Ѱ��Ψһ�ĸ��ڵ㣬�ҵ�֮��dfs
            dfs(i);
            cout << max(dp[i][0],dp[i][1]) << "\n";
            break;
        }
    }
    return 0;
}
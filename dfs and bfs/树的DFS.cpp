#include <iostream>
#include <vector>
using namespace std;

const int N = 200010;
vector<int> g[N];
// 值为i的数通过p索引到dfs序列中对应的下标，j通过q索引到dfs序列中下标为j的值
int sz[N], index[N], xulie[N], top;

void dfs(int u) {
    sz[u] = 1;
    index[u] = top;
    xulie[top] = u;
    top++;
    for (auto x : g[u]) {
        dfs(x);
        sz[u] += sz[x];
    }
}
//0 1 2 8 3 4 6 5 7 p[1]-p[9]
//1 2 3 5 6 8 7 9 4 q[0]-q[8]
//我要怎么知道值为i在dfs序列中的下标呢，所以我要使用一个数组来保存值为i在dfs序列中的下标;
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        g[x].push_back(i);
    }
    dfs(1);
    while (m--) {
        int u, k;
        cin >> u >> k;
        if (k > sz[u]) cout << -1 << endl;
        else cout << xulie[index[u] + k - 1] << endl;
    }
    return 0;
}
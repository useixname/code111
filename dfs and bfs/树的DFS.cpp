#include <iostream>
#include <vector>
using namespace std;

const int N = 200010;
vector<int> g[N];
// ֵΪi����ͨ��p������dfs�����ж�Ӧ���±꣬jͨ��q������dfs�������±�Ϊj��ֵ
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
//��Ҫ��ô֪��ֵΪi��dfs�����е��±��أ�������Ҫʹ��һ������������ֵΪi��dfs�����е��±�;
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
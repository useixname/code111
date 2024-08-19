#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 500005;
int n, m, s[MAXN]; //区间和

int lowbit(int x) { // 提取x的低位2次幂数
    return x & -x;
}

void add(int x, int k) { // 点修
    while (x <= n) {
        s[x] += k;
        x += lowbit(x);
    }
}

int sum(int x) { // 前缀和
    int t = 0;
    while (x) {
        t += s[x];
        x -= lowbit(x);
    }
    return t;
}

signed main() {
    FILE* pf = fopen("P2068_1.in", "r");
    FILE* pr = fopen("P2068_1.out", "w");

    fscanf(pf, "%d", &n);
    fscanf(pf, "%d", &m);

    // 初始化数组
    memset(s, 0, sizeof(s));
    
    char op;
    int x, y;
    for (int i = 1; i <= m; i++) {
        fscanf(pf, " %c %d %d", &op, &x, &y);
        if (op == 'x') {
            add(x, y);
        } else {
            int result = sum(y) - sum(x - 1);
            fprintf(pr, "%lld\n", result);
        }
    }

    fclose(pf);
    fclose(pr);

    return 0;
}

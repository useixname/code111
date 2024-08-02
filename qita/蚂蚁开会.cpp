#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PI;
map<PI, int> M; 
map<PI, bool> vis;
int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}
int n;
int ans = 0;

int main() {
    cin >> n;  // 读取线段数量
    for (int i = 1; i <= n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;  // 读取线段的两个端点
        int g = gcd(abs(x1 - x2), abs(y1 - y2));  // 计算两个端点差值的最大公约数
        int ax = (x2 - x1) / g;  // 计算步长
        int ay = (y2 - y1) / g;  // 计算步长
        while (x1 != x2 || y1 != y2) {
            M[PI(x1, y1)]++;  // 更新点被覆盖次数
            if (M[PI(x1, y1)] >= 2 && !vis[PI(x1, y1)]) {  // 判断是否为重叠点
                ans++;
                vis[PI(x1, y1)] = 1;  // 标记重叠点
            }
            x1 += ax;
            y1 += ay;
        }
        M[{x2, y2}]++;  // 处理线段终点
        if (M[PI(x2, y2)] >= 2 && !vis[PI(x2, y2)]) {  // 判断终点是否为重叠点
            ans++;
            vis[PI(x2, y2)] = 1;  // 标记重叠点
        }
    }
    cout << ans << endl;  // 输出重叠点数量
    return 0;
}

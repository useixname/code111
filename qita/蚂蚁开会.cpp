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
    cin >> n;  // ��ȡ�߶�����
    for (int i = 1; i <= n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;  // ��ȡ�߶ε������˵�
        int g = gcd(abs(x1 - x2), abs(y1 - y2));  // ���������˵��ֵ�����Լ��
        int ax = (x2 - x1) / g;  // ���㲽��
        int ay = (y2 - y1) / g;  // ���㲽��
        while (x1 != x2 || y1 != y2) {
            M[PI(x1, y1)]++;  // ���µ㱻���Ǵ���
            if (M[PI(x1, y1)] >= 2 && !vis[PI(x1, y1)]) {  // �ж��Ƿ�Ϊ�ص���
                ans++;
                vis[PI(x1, y1)] = 1;  // ����ص���
            }
            x1 += ax;
            y1 += ay;
        }
        M[{x2, y2}]++;  // �����߶��յ�
        if (M[PI(x2, y2)] >= 2 && !vis[PI(x2, y2)]) {  // �ж��յ��Ƿ�Ϊ�ص���
            ans++;
            vis[PI(x2, y2)] = 1;  // ����ص���
        }
    }
    cout << ans << endl;  // ����ص�������
    return 0;
}

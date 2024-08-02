#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100010;

int n;
int a[N][25];
int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		for (int j = 0; j <= 20; ++j) {
			a[i][j] = (x >> j) & 1;
			a[i][j] ^= a[i - 1][j];
		}
	}
	LL ans = 0;
	for (int j = 0; j <= 20; ++j) {
		map<int, int> m;
		m[0]++;
		for (int i = 1; i <= n; ++i) {
			int x = m[a[i][j] ^ 1];
			ans += 1LL * (1 << j) * x;
			m[a[i][j]]++;
		}
	}
	cout << ans << '\n';
	return 0;
}

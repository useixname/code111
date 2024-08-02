#include <bits/stdc++.h>
using namespace std;

struct s {
	int l, s;
} arr[100010];
 
int n, len;
int check(int mid) {
	int cnt = 0;
	pair<int, int> q[100010];
	for (int i = 1; i <= n; i++) {
		if (arr[i].s > mid) continue;
		int t = mid - arr[i].s;
		int l = max(1, arr[i].l - t), r = min((long long)len, (long long) arr[i].l + t);
		q[cnt++] = {l, r};
	}
	sort(q, q + cnt);
	int en = q[0].second;
	if(q[0].first!=1) return 0;
	
	for (int i = 1; i < cnt; i++) {
		if (q[i].first > en + 1) {
            //这样是正确了，因为en代表的是第en段管道已经被水覆盖了
            //接下来只需保证q[i].first-1<=en即可.
			return 0;
		} 
		en=max(en,q[i].second);
	}
	return en>=len;
}
int main() {
	cin >> n >> len;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i].l >> arr[i].s;
	}
	int l = 0, r = 2e9 + 10;
	while (l < r) {
		int mid = (long long)l + r >> 1 ;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	cout << l << endl;
	return 0;
}
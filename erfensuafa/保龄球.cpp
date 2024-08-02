#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, m;
struct node {
    int value, index;
    bool operator<(const node &pa) const {
        return value < pa.value;
    }
} a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].value;
        a[i].index = i;
    }
    sort(a + 1, a + n + 1);

    cin >> m;
    while (m--) {
        int k;
        cin >> k;
        int l = 1, r = n;
        int ans = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (a[mid].value < k) {
                l = mid + 1;
            } else if (a[mid].value > k) {
                r = mid - 1;
            } else {
                ans = a[mid].index;
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool cmp(vector<ll> &a, vector<ll> &b) {
    return a[0] + a[1] < b[0] + b[1];
} 

int main() {
    int n;
    cin >> n;
    vector<vector<ll> > arr(n, vector<ll>(2));
    for (int i = 0; i < n; i++) {
        ll x, y, z;
        cin >> x >> y >> z;
        arr[i][0] = x + y;
        arr[i][1] = z;
    }
    sort(arr.begin(), arr.end(), cmp);
    ll cur = 0, ans = 0;
    for (int i = 0; i < n; i++) {
//        cout << arr[i][0] << "  " << arr[i][1] << endl;
        cur += arr[i][0];
        ans += cur;
        cur += arr[i][1];
    }
    cout << ans << endl;
    return 0;
}